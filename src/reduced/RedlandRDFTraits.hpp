#ifndef RDF_TRAITS_HPP_INCLUDED
#define RDF_TRAITS_HPP_INCLUDED

#include "redland.hpp"
#include <memory>
#include <vector>

namespace Arvida
{
namespace RDF
{

typedef Redland::Node Node;
typedef Redland::Node * NodePtr;
typedef Redland::Node & NodeRef;

struct Context
{
    Redland::World &world;
    Redland::Namespaces &namespaces;
    Redland::Model &model;
    const std::string &path;
    const void *user_data;

    Context(Redland::World &world, Redland::Namespaces &namespaces, Redland::Model &model, const std::string &path,
            const void *user_data = 0)
        : world(world), namespaces(namespaces), model(model), path(path), user_data(user_data)
    {
    }
    Context(const Context &ctx)
        : world(ctx.world), namespaces(ctx.namespaces), model(ctx.model), path(ctx.path), user_data(ctx.user_data)
    {
    }
    Context(const Context &ctx, const std::string &path)
        : world(ctx.world), namespaces(ctx.namespaces), model(ctx.model), path(path), user_data(ctx.user_data)
    {
    }
};

inline bool isNodeExists(Redland::Model &model, const Redland::Node &node)
{
    librdf_iterator *it = librdf_model_get_arcs_in(model.c_obj(), node.c_obj());
    if (it)
    {
        const bool found = !librdf_iterator_end(it);
        librdf_free_iterator(it);
        if (found)
            return true;
    }

    it = librdf_model_get_arcs_out(model.c_obj(), node.c_obj());
    if (it)
    {
        const bool found = !librdf_iterator_end(it);
        librdf_free_iterator(it);
        if (found)
            return true;
    }

    return false;
}

template<class T>
inline bool isValidValue(const T &value)
{
    return true;
}

template<class T>
inline bool isValidValue(const std::shared_ptr<T> &value)
{
    return value.operator bool();
}

//

enum PathType
{
    NO_PATH, RELATIVE_PATH, ABSOLUTE_PATH
};

// pathOf

template<class T>
inline std::string pathOf(const Context &ctx, const T &value)
{
    return "";
}

template<class T>
inline std::string pathOf(const Context &ctx, const std::shared_ptr<T> &value)
{
    if (value)
        return pathOf(ctx, *value);
    else
        return "";
}

template<class T>
inline PathType pathTypeOf(const Context &ctx, const T &value)
{
    return "";
}

template<class T>
inline PathType pathTypeOf(const Context &ctx, const std::shared_ptr<T> &value)
{
    if (value)
        return pathTypeOf(ctx, *value);
    else
        return NO_PATH;
}

// createRDFNode

template<class T>
Node createRDFNode(const Context &ctx, const T &value, PathType memberPathType, const std::string &memberPath)
{
    const PathType thatPathType = pathTypeOf(ctx, value);
    Redland::Node thatNode;
    if (thatPathType == NO_PATH && memberPathType == NO_PATH)
    {
        thatNode = Redland::Node::make_blank_node(ctx.world);
        if (!isNodeExists(ctx.model, thatNode))
            toRDF(ctx, thatNode, value);
    }
    else
    {
        std::string thatPath;
        if (thatPathType == ABSOLUTE_PATH)
            thatPath = pathOf(ctx, value);
        else {
            switch (memberPathType)
            {
                case NO_PATH:
                    thatPath = ctx.path;
                    break;
                case RELATIVE_PATH:
                    thatPath = ctx.path + memberPath;
                    break;
                case ABSOLUTE_PATH:
                    thatPath = memberPath;
                    break;
            }
            if (thatPathType == RELATIVE_PATH)
                thatPath += pathOf(ctx, value);
        }
        thatNode = Redland::Node::make_uri_node(ctx.world, thatPath);
        Arvida::RDF::Context thatCtx(ctx, thatPath);
        if (!isNodeExists(ctx.model, thatNode))
            toRDF(thatCtx, thatNode, value);
    }
    return thatNode;
}

// toRDF

template<class T>
Node toRDF(const Context &ctx, const T &value)
{
    Redland::Node valueNode = Redland::Node::make_blank_node(ctx.world);
    return toRDF(ctx, valueNode, value);
}

template<class T>
inline NodeRef toRDF(const Context &ctx, NodeRef thisNode, const T &value)
{
    return value.toRDF(ctx, thisNode);
}

template<class T>
inline NodeRef toRDF(const Context &ctx, NodeRef thisNode, const std::shared_ptr<T> &value)
{
    if (value)
        return toRDF(ctx, thisNode, *value);
    else
    {
        if (!thisNode.is_blank())
            thisNode = Redland::Node::make_blank_node(ctx.world);
        return thisNode;
    }
}
//#define XSD_NS
//"12345^^<http://www.w3.org/2001/XMLSchema#int>"
template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const double &value)
{
    Redland::Uri xsd_double(ctx.world, "http://www.w3.org/2001/XMLSchema#double");
    _this = Redland::Node::make_typed_literal_node(ctx.world, std::to_string(value), xsd_double);
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const float &value)
{
    Redland::Uri xsd_double(ctx.world, "http://www.w3.org/2001/XMLSchema#float");
    _this = Redland::Node::make_typed_literal_node(ctx.world, std::to_string(value), xsd_double);
    return _this;
}

template<class T>
bool fromRDF(const Context &ctx, const NodeRef thisNode, T &value)
{
    return value.fromRDF(ctx, thisNode);
}

/*
 template <>
 inline bool fromRDF(const Context &ctx, const NodeRef _this0, double &value)
 {
 if (_this0.is_literal_type(SORD_NS_XSD "integer") ||
 _this0.is_literal_type(SORD_NS_XSD "decimal") ||
 _this0.is_literal_type(SORD_NS_XSD "double"))
 {
 char* endptr;
 value = serd_strtod(_this0.to_c_string(), &endptr);
 return true;
 }

 return false;
 }

 template <>
 inline bool fromRDF(const Context &ctx, const NodeRef _this0, float &value)
 {
 if (_this0.is_literal_type(SORD_NS_XSD "integer") ||
 _this0.is_literal_type(SORD_NS_XSD "decimal") ||
 _this0.is_literal_type(SORD_NS_XSD "double"))
 {
 char* endptr;
 value = serd_strtod(_this0.to_c_string(), &endptr);
 return true;
 }

 return false;
 }
 */
} // namespace Arvida
} // namespace RDF

#endif
