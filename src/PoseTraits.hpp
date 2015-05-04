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

template <>
bool fromRDF(const Context &ctx, const NodeRef _this0, ::Rotation &value)
{
    using namespace Sord;

    Arvida::RDF::Triple triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:Rotation3D"));

    // 1. Check $this
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    // 2. Check blank _b0
    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "vom:quantityValue"), Node());
    if (!triple.is_valid())
        return false;
    const Node _b0 = triple.object;

    if (!Arvida::RDF::check_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector4D")))
        return false;

    if (!Arvida::RDF::check_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Quaternion")))
        return false;

    // maths:x
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:x"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setX(tmp_value);
    }

    // maths:y
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:y"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setY(tmp_value);
    }

    // maths:z
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:z"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setZ(tmp_value);
    }

    // maths:w
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

template <>
bool fromRDF(const Context &ctx, const NodeRef _this0, ::Translation &value)
{
    using namespace Sord;

    Arvida::RDF::Triple triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:Translation3D"));

    // 1. Check $this
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    // 2. Check blank _b0
    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "vom:quantityValue"), Node());
    if (!triple.is_valid())
        return false;
    const Node _b0 = triple.object;

    if (!Arvida::RDF::check_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector3D")))
        return false;

    // maths:x
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:x"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setX(tmp_value);
    }

    // maths:y
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:y"), Node());
    if (!triple.is_valid())
        return false;
    {
        double tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setY(tmp_value);
    }

    // maths:z
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
    {
        const std::string path_14 = ctx.path + "/transl";
        Arvida::RDF::Context ctx_14(ctx, path_14);
        Sord::URI node_14(ctx.model.world(), path_14);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:translation"), Arvida::RDF::toRDF(ctx_14, node_14, value.getTranslation()));
    }
    {
        const std::string path_17 = ctx.path + "/rot";
        Arvida::RDF::Context ctx_17(ctx, path_17);
        Sord::URI node_17(ctx.model.world(), path_17);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:rotation"), Arvida::RDF::toRDF(ctx_17, node_17, value.getRotation()));
    }
    return _this;
}


template <>
bool fromRDF(const Context &ctx, const NodeRef _this0, ::Pose &value)
{
    using namespace Sord;

    Arvida::RDF::Triple triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "spatial:SpatialRelationship"));

    // 1. Check $this
    if (!triple.is_valid())
    {
        return false;
    }
    const Node _this = triple.subject;

    // 2. Check blank _b1
    triple = Arvida::RDF::find_triple(ctx.model, Node(), Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));
    if (!triple.is_valid())
    {
        return false;
    }
    const Node _b1 = triple.subject;

    // 3. Check blank _b1
    if (!Arvida::RDF::check_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), _b1))
    {
        return false;
    }

    // 4. Check blank _b0
    triple = Arvida::RDF::find_triple(ctx.model, Node(), Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));
    if (!triple.is_valid())
    {
        return false;
    }
    Node _b0 = triple.subject;

    // 5. Check blank _b0
    if (!Arvida::RDF::check_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), _b0))
    {
        return false;
    }

    // 6. Check $that
    {
        const std::string path_14 = ctx.path + "/transl";
        Arvida::RDF::Context ctx_14(ctx, path_14);
        Sord::URI node_14(ctx.model.world(), path_14);

        triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:translation"), node_14);
        if (!triple.is_valid())
            return false;

        {
            ::Translation tmp_value;
            if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
                return false;
            value.setTranslation(tmp_value);
        }
    }

    // 7. Check $that
    {
        const std::string path_17 = ctx.path + "/rot";
        Arvida::RDF::Context ctx_17(ctx, path_17);
        Sord::URI node_17(ctx.model.world(), path_17);

        triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:rotation"), node_17);
        if (!triple.is_valid())
            return false;

        {
            ::Rotation tmp_value;
            if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
                return false;
            value.setRotation(tmp_value);
        }
    }

    return true;
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
