#ifndef RDF_TRAITS_HPP_INCLUDED
#define RDF_TRAITS_HPP_INCLUDED

#include "sord/sordmm.hpp"
#include "serd/serd.h"
#include <memory>

namespace Arvida {
namespace RDF {

typedef Sord::Node Node;
typedef Sord::Node * NodePtr;
typedef Sord::Node & NodeRef;

struct Context
{
    Sord::Model &model;
    const std::string &path;

    Context(Sord::Model &model, const std::string &path) : model(model), path(path) { }
    Context(const Context &ctx) : model(ctx.model), path(ctx.path) { }
    Context(const Context &ctx, const std::string &path) : model(ctx.model), path(path) { }
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
inline NodeRef toRDF(const Context &ctx, NodeRef thisNode, const std::shared_ptr<const T> &value)
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
