#ifndef POSE_TRAITS_HPP_INCLUDED
#define POSE_TRAITS_HPP_INCLUDED

#include "RDFTraits.hpp"
#include "Pose.hpp"

// Module name: CodegenExample

namespace Arvida
{
namespace RDF
{


template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Rotation &value)
{
    using namespace Sord;
    Node _b0 = Node::blank_id(ctx.model.world());

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:Rotation3D"));
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "vom:quantityValue"), _b0);
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector4D"));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Quaternion"));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:x"), Arvida::RDF::toRDF(ctx, value.getX()));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:y"), Arvida::RDF::toRDF(ctx, value.getY()));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:z"), Arvida::RDF::toRDF(ctx, value.getZ()));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:w"), Arvida::RDF::toRDF(ctx, value.getW()));


    return _this;
}
template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Translation &value)
{
    using namespace Sord;
    Node _b0 = Node::blank_id(ctx.model.world());

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:Translation3D"));
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "vom:quantityValue"), _b0);
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector3D"));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:x"), Arvida::RDF::toRDF(ctx, value.getX()));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:y"), Arvida::RDF::toRDF(ctx, value.getY()));
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:z"), Arvida::RDF::toRDF(ctx, value.getZ()));


    return _this;
}
template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Pose &value)
{
    using namespace Sord;
    Node _b0 = Node::blank_id(ctx.model.world());
    Node _b1 = Node::blank_id(ctx.model.world());

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:SpatialRelationship"));
    ctx.model.add_statement(_b1, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), _b1);
    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), _b0);
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:translation"), Arvida::RDF::toRDF(ctx, value.getTranslation()));
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:rotation"), Arvida::RDF::toRDF(ctx, value.getRotation()));


    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Device &value)
{
    using namespace Sord;
    Node _b0 = Node::blank_id(ctx.model.world());
    Node _b1 = Node::blank_id(ctx.model.world());


    return _this;
}

} // namespace Arvida
} // namespace RDF

#endif
