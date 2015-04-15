#ifndef RDF_TRAITS_HPP_INCLUDED
#define RDF_TRAITS_HPP_INCLUDED

#include "sord/sordmm.hpp"
#include "serd/serd.h"

namespace Arvida {
namespace RDF {

struct Context
{
    Sord::Model &model;
    Context(Sord::Model &model) : model(model) { }
};

template< class T >
struct RDFTraits
{

};

template < class T >
Sord::Node toRDF(const Context &ctx, const T &value)
{
    Sord::Node node;
    RDFTraits<T>::toRDF(ctx, node, value);
    return node;
}

} // namespace Arvida
} // namespace RDF

#endif
