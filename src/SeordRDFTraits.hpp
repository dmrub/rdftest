#ifndef SEORD_RDF_TRAITS_HPP_INCLUDED
#define SEORD_RDF_TRAITS_HPP_INCLUDED

#include "sord/sordmm.hpp"
#include "serd/serd.h"
#include <memory>
#include <vector>

namespace Arvida {
namespace RDF {

typedef Sord::Node Node;
typedef Sord::Node * NodePtr;
typedef Sord::Node & NodeRef;

struct Context
{
    Sord::Model &model;
    const std::string &base_path;
    const std::string &path;
    const void *user_data;

    Context(Sord::Model &model, const std::string &base_path, const std::string &path, const void *user_data = 0) : model(model), base_path(base_path), path(path), user_data(user_data) { }
    Context(Sord::Model &model, const std::string &path, const void *user_data = 0) : model(model), base_path(path), path(path), user_data(user_data) { }
    Context(const Context &ctx) : model(ctx.model), base_path(ctx.base_path), path(ctx.path), user_data(ctx.user_data) { }
    Context(const Context &ctx, const std::string &path) : model(ctx.model), base_path(ctx.base_path), path(path), user_data(ctx.user_data) { }
};

struct Triple
{
    Sord::Node subject;
    Sord::Node predicate;
    Sord::Node object;

    Triple() : subject(), predicate(), object() { }

    Triple(const Sord::Node &subject, const Sord::Node &predicate, const Sord::Node &object)
        : subject(subject)
        , predicate(predicate)
        , object(object)
    { }

    bool is_valid() const
    {
        return subject.is_valid() && predicate.is_valid() && object.is_valid();
    }
};

inline bool check_triple(Sord::Model &model, const Sord::Node &subject, const Sord::Node &predicate, const Sord::Node &object)
{
    Sord::Iter iter = model.find(subject, predicate, object);
    return !iter.end();
}

inline Triple find_triple(Sord::Model &model, const Sord::Node &subject, const Sord::Node &predicate, const Sord::Node &object)
{
    Sord::Iter iter = model.find(subject, predicate, object);
    if (iter.end())
        return Triple();
    return Triple(iter.get_subject(), iter.get_predicate(), iter.get_object());
}

inline bool isNodeExists(Sord::Model &model, const Sord::Node &node)
{
    Sord::Node empty;
    {
        Sord::Iter iter = model.find(node, empty, empty);
        if (!iter.end())
            return true;
    }
    {
        Sord::Iter iter = model.find(empty, empty, node);
        if (!iter.end())
            return true;
    }
    {
        Sord::Iter iter = model.find(empty, node, empty);
        if (!iter.end())
            return true;
    }
    return false;
}

template <class T>
inline bool isValidValue(const T &value)
{
    return true;
}

template < class T >
inline bool isValidValue(const std::shared_ptr<T> &value)
{
    return value.operator bool();
}

// PathType

enum PathType
{
    NO_PATH, RELATIVE_PATH, RELATIVE_TO_BASE_PATH, ABSOLUTE_PATH
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
    return NO_PATH;
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
    if (thatPathType == NO_PATH && memberPathType == NO_PATH)
    {
        Node thatNode(Node::blank_id(ctx.model.world()));
        return thatNode;
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
                case RELATIVE_TO_BASE_PATH:
                    thatPath = ctx.base_path + memberPath;
                    break;
                case ABSOLUTE_PATH:
                    thatPath = memberPath;
                    break;
            }
            if (thatPathType == RELATIVE_PATH)
                thatPath += pathOf(ctx, value);
        }
        Arvida::RDF::Context thatCtx(ctx, thatPath);
        Sord::URI thatNode(ctx.model.world(), thatPath);
        return thatNode;
    }
}

template<class T>
Node createRDFNodeAndSerialize(const Context &ctx, const T &value, PathType memberPathType, const std::string &memberPath)
{
    const PathType thatPathType = pathTypeOf(ctx, value);
    if (thatPathType == NO_PATH && memberPathType == NO_PATH)
    {
        Node thatNode(Node::blank_id(ctx.model.world()));
        if (!isNodeExists(ctx.model, thatNode))
            toRDF(ctx, thatNode, value);
        return thatNode;
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
        Arvida::RDF::Context thatCtx(ctx, thatPath);
        Sord::URI thatNode(ctx.model.world(), thatPath);
        if (!isNodeExists(ctx.model, thatNode))
            toRDF(thatCtx, thatNode, value);
        return thatNode;
    }
}

// toRDF

template < class T >
Node toRDF(const Context &ctx, const T &value)
{
    Sord::Node valueNode = Sord::Node::blank_id(ctx.model.world());
    return toRDF(ctx, valueNode, value);
}

template < class T >
inline NodeRef toRDF(const Context &ctx, NodeRef thisNode, const T &value)
{
    return value.toRDF(ctx, thisNode);
}

template < class T >
inline NodeRef toRDF(const Context &ctx, NodeRef thisNode, const std::shared_ptr<T> &value)
{
    if (value)
        return toRDF(ctx, thisNode, *value);
    else
    {
        if (!thisNode.is_blank())
            thisNode = Sord::Node::blank_id(ctx.model.world());
        return thisNode;
    }
}

template < class T >
inline NodeRef toRDF(const Context &ctx, NodeRef thisNode, const std::vector<T> &value)
{
    using namespace Sord;
    ctx.model.add_statement(thisNode, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "core:Container"));

    for (auto it = std::begin(value); it != std::end(value); ++it)
    {
        const auto & _that = *it;
        ctx.model.add_statement(thisNode, Curie(ctx.model.world(), "core:member"), Arvida::RDF::toRDF(ctx, _that));
    }
    return thisNode;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const double &value)
{
    const SerdNode val = serd_node_new_decimal(value, 7);
    const SerdNode type = serd_node_from_string(SERD_URI, (const uint8_t*) SORD_NS_XSD "double");

    _this = Sord::Node(ctx.model.world(),
        sord_node_from_serd_node(ctx.model.world().c_obj(), ctx.model.world().prefixes().c_obj(), &val, &type, NULL),
        false);
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const float &value)
{
    const SerdNode val = serd_node_new_decimal(value, 7);
    const SerdNode type = serd_node_from_string(SERD_URI, (const uint8_t*) SORD_NS_XSD "float");

    _this = Sord::Node(ctx.model.world(),
        sord_node_from_serd_node(ctx.model.world().c_obj(), ctx.model.world().prefixes().c_obj(), &val, &type, NULL),
        false);
    return _this;
}


template < class T >
bool fromRDF(const Context &ctx, const NodeRef thisNode, T &value)
{
    return value.fromRDF(ctx, thisNode);
}

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

} // namespace Arvida
} // namespace RDF

#endif
