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
    Context(Sord::Model &model) : model(model) { }
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

} // namespace Arvida
} // namespace RDF

#endif
