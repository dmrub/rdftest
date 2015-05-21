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
    Node _b1 = Node::blank_id(ctx.model.world());
    Node _b0 = Node::blank_id(ctx.model.world());
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:SpatialRelationship"));

    ctx.model.add_statement(_b1, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), _b1);

    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), _b0);
    {
        const std::string path_23 = ctx.path + "/transl";
        Arvida::RDF::Context ctx_23(ctx, path_23);
        Sord::URI node_23(ctx.model.world(), path_23);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:translation"), Arvida::RDF::toRDF(ctx_23, node_23, value.getTranslation()));
    }
    {
        const std::string path_31 = ctx.path + "/rot";
        Arvida::RDF::Context ctx_31(ctx, path_31);
        Sord::URI node_31(ctx.model.world(), path_31);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:rotation"), Arvida::RDF::toRDF(ctx_31, node_31, value.getRotation()));
    }
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Device &value)
{
    using namespace Sord;
    return _this;
}

template <>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Rotation &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:Rotation3D"));

    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "vom:quantityValue"), Node());
    if (!triple.is_valid())
        return false;
    const Node _b0 = triple.object;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector4D"));
    if (!triple.is_valid())
        return false;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Quaternion"));
    if (!triple.is_valid())
        return false;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:x"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setX(tmp_value);
    }

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:y"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setY(tmp_value);
    }

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:z"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setZ(tmp_value);
    }

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:w"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setW(tmp_value);
    }
    return true;
}

template <>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Translation &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:Translation3D"));

    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "vom:quantityValue"), Node());
    if (!triple.is_valid())
        return false;
    const Node _b0 = triple.object;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector3D"));
    if (!triple.is_valid())
        return false;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:x"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setX(tmp_value);
    }

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:y"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setY(tmp_value);
    }

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:z"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setZ(tmp_value);
    }

    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Pose &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:SpatialRelationship"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    triple = Arvida::RDF::find_triple(ctx.model, Node(), Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));
    if (!triple.is_valid())
        return false;
    const Node _b1 = triple.subject;

    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), _b1);
    if (!triple.is_valid())
        return false;

    triple = Arvida::RDF::find_triple(ctx.model, Node(), Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));
    if (!triple.is_valid())
        return false;
    const Node _b0 = triple.subject;

    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), _b0);
    if (!triple.is_valid())
        return false;

    {
        const std::string path_27 = ctx.path + "/transl";
        Arvida::RDF::Context ctx_27(ctx, path_27);
        Sord::URI node_27(ctx.model.world(), path_27);
        triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:translation"), node_27);
        if (!triple.is_valid())
            return false;

        {
            ::Translation tmp_value;
            if (!Arvida::RDF::fromRDF(ctx_27, triple.object, tmp_value))
                return false;
            value.setTranslation(tmp_value);
        }
    }

    {
        const std::string path_35 = ctx.path + "/rot";
        Arvida::RDF::Context ctx_35(ctx, path_35);
        Sord::URI node_35(ctx.model.world(), path_35);
        triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:rotation"), node_35);
        if (!triple.is_valid())
            return false;

        {
            ::Rotation tmp_value;
            if (!Arvida::RDF::fromRDF(ctx_35, triple.object, tmp_value))
                return false;
            value.setRotation(tmp_value);
        }
    }
    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Device &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    return true;
}

} // namespace Arvida
} // namespace RDF

#endif
