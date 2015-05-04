#ifndef RDF_TRAITS_HPP_INCLUDED
#define RDF_TRAITS_HPP_INCLUDED

#include "sord/sordmm.hpp"
#include "serd/serd.h"

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

template < class T >
Node toRDF(const Context &ctx, const T &value)
{
    Sord::Node valueNode = Sord::Node::blank_id(ctx.model.world());
    return toRDF<T>(ctx, valueNode, value);
}

template < class T >
NodeRef toRDF(const Context &ctx, NodeRef thisNode, const T &value)
{
    return value.toRDF(ctx, thisNode);
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

} // namespace Arvida
} // namespace RDF

#endif
