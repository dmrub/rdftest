#ifndef POSE_TRAITS_HPP_INCLUDED
#define POSE_TRAITS_HPP_INCLUDED

#include "SeordRDFTraits.hpp"
#include "Pose.hpp"

namespace Arvida
{
namespace RDF
{

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Rotation &value)
{
     Node _b0 = Node::blank_id(ctx.model.world());
     {
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:Rotation3D"));

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityValue"), _b0);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Vector4D"));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Quaternion"));

     }
     // Serialize member getX
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getX();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), that_node);

     }
     // Serialize member getY
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getY();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), that_node);

     }
     // Serialize member getZ
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getZ();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), that_node);

     }
     // Serialize member getW
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getW();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:w"), that_node);

     }




    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Translation &value)
{
     Node _b0 = Node::blank_id(ctx.model.world());
     {
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:Translation3D"));

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityValue"), _b0);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Vector3D"));

     }
     // Serialize member getX
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getX();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), that_node);

     }
     // Serialize member getY
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getY();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), that_node);

     }
     // Serialize member getZ
     {
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         const auto & _that = value.getZ();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), that_node);

     }



    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Pose &value)
{
     Node _b1 = Node::blank_id(ctx.model.world());
     Node _b0 = Node::blank_id(ctx.model.world());
     {
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:SpatialRelationship"));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), _b0);

          ctx.model.add_statement(_b1, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), _b1);

     }
     // Serialize member getTranslation
     {
         const std::string that_path = ctx.path + "/transl";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         const auto & _that = value.getTranslation();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:translation"), that_node);

     }

     // Serialize member getRotation
     {
         const std::string that_path = ctx.path + "/rot";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         const auto & _that = value.getRotation();
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:rotation"), that_node);

     }

    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Device &value)
{
     {
     }
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
