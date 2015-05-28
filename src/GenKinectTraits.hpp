#ifndef KINECT_TRAITS
#define KINECT_TRAITS

#include "RDFTraits.hpp"
#include "Kinect.hpp"
#include "KinectUtils.hpp"

namespace Arvida
{
namespace RDF
{


inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::CoordinateSystem &value)
{
     {
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:CoordinateSystem"));

     }
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::RightHandedCartesianCoordinateSystem3D &value)
{
    toRDF_impl(ctx, _this, static_cast<const ::CoordinateSystem &>(value));
     {
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem3D"));

     }
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Quantity &value)
{
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Rotation &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Quantity &>(value));
    Node _b0 = Node::blank_id(ctx.model.world());
     {
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:Rotation3D"));

    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityValue"), _b0);

    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityKind"), Sord::Curie(ctx.model.world(), "vom:Angle"));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Vector4D"));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Quaternion"));


     }
     // Serialize member getX
     {
         const auto & _that = value.getX();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), that_node);


     }
     }
     // Serialize member getY
     {
         const auto & _that = value.getY();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), that_node);


     }
     }
     // Serialize member getZ
     {
         const auto & _that = value.getZ();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), that_node);


     }
     }
     // Serialize member getW
     {
         const auto & _that = value.getW();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:w"), that_node);


     }
     }

    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Translation &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Quantity &>(value));
    Node _b0 = Node::blank_id(ctx.model.world());
    {
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:Translation3D"));
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityValue"), _b0);
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityKind"), Sord::Curie(ctx.model.world(), "vom:Length"));
          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Vector3D"));
    }
     // Serialize member getX
    {
         const auto & _that = value.getX();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), that_node);
         }
    }
     // Serialize member getY
    {
         const auto & _that = value.getY();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), that_node);
         }
    }
     // Serialize member getZ
    {
         const auto & _that = value.getZ();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Sord::Node that_node(Sord::Node::blank_id(ctx.model.world()));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), that_node);
    }
     }
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Segment &value)
{
    // Serialize member getSourceCoordinateSystem
    {
        const auto & _that = value.getSourceCoordinateSystem();
         if (Arvida::RDF::isValidValue(_that))
         {
         const std::string that_path = (::get_coordinate_systems_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), that_node);
         }
    }
     // Serialize member getTargetCoordinateSystem
    {
        const auto & _that = value.getTargetCoordinateSystem();
         if (Arvida::RDF::isValidValue(_that))
         {
         const std::string that_path = (::get_coordinate_systems_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), that_node);
         }
    }
    // Serialize member getTranslation
    {
        const auto & _that = value.getTranslation();
        if (Arvida::RDF::isValidValue(_that))
        {
         const std::string that_path = (::get_quantities_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
            Arvida::RDF::toRDF(that_ctx, that_node, _that);
            ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:translation"), that_node);
        }
    }

    // Serialize member getRotation
     {
         const auto & _that = value.getRotation();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_quantities_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:rotation"), that_node);


         }
     }

    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Joint &value)
{
    toRDF_impl(ctx, _this, static_cast<const ::Segment &>(value));
     {
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "skel:Joint"));

     }
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Bone &value)
{

    toRDF_impl(ctx, _this, static_cast<const ::Segment &>(value));
     {
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "skel:Bone"));
}
     // Serialize member getStartJoint
     {
         const auto & _that = value.getStartJoint();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);
          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:startJoint"), that_node);
         }
     }
     // Serialize member getEndJoint
     {
         const auto & _that = value.getEndJoint();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:endJoint"), that_node);
         }
     }
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Skeleton &value)
{
     {

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "skel:Skeleton"));


     }
     // Serialize member getBones
     {
         const auto & _that = value.getBones();
         if (Arvida::RDF::isValidValue(_that))
         {





         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = (::get_segments_path(ctx)) + "/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:skeletonBone"), element_node);

         }
         }
     }
     // Serialize member getJoints
    {
         const auto & _that = value.getJoints();
         if (Arvida::RDF::isValidValue(_that))
         {





         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = (::get_segments_path(ctx)) + "/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:skeletonJoint"), element_node);

         }
         }
     }
     // Serialize member getRoots
     {
         const auto & _that = value.getRoots();
         if (Arvida::RDF::isValidValue(_that))
         {





         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = (::get_segments_path(ctx)) + "/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:skeletonRoot"), element_node);

         }
         }
     }
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::SkeletonTrackingService &value)
{
     {

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "service:SkeletonTrackingService"));


     }
     // Serialize member getCoordinateSystems
     {
         const auto & _that = value.getCoordinateSystems();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/coordinateSystems/";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);


          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "service:trackerCoordinateSystems"), that_node);
          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "core:Container"));



         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/coordinateSystems/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);



          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "core:member"), element_node);

         }
         }
     }
     // Serialize member getQuantities
     {
         const auto & _that = value.getQuantities();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/quantities/";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "service:trackerQuantities"), that_node);
          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "core:Container"));


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/quantities/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);



          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "core:member"), element_node);

         }
         }
     }
     // Serialize member getSegments
     {
         const auto & _that = value.getSegments();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/segments/";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "service:trackerSegments"), that_node);
          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "core:Container"));


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/segments/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);



          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "core:member"), element_node);

         }
         }
     }
     // Serialize member getSkeletons
     {
         const auto & _that = value.getSkeletons();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/skeletons/";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "service:trackerSkeletons"), that_node);
          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "core:Container"));


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/skeletons/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Sord::URI element_node(ctx.model.world(), element_path);
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
             Arvida::RDF::toRDF(element_ctx, element_node, _element);



          ctx.model.add_statement(that_node, Sord::Curie(ctx.model.world(), "core:member"), element_node);

         }
         }
     }
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::TrackingServiceProvider &value)
{
     {

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "core:TrackingServiceProvider"));


     }
     // Serialize member getSkeletonTracker
    {
        const auto & _that = value.getSkeletonTracker();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/skelTracker";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Sord::URI that_node(ctx.model.world(), that_path);
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
         Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "core:service"), that_node);


         }
    }
    return _this;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::CoordinateSystem &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:CoordinateSystem"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::RightHandedCartesianCoordinateSystem3D &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem3D"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Quantity &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    return true;
}

template<>
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
    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "vom:quantityKind"), Curie(ctx.model.world(), "vom:Angle"));
    if (!triple.is_valid())
        return false;

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
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setX(tmp_value);
    }
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:y"), Node());
    if (!triple.is_valid())
        return false;
    {
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setY(tmp_value);
    }
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:z"), Node());
    if (!triple.is_valid())
        return false;
    {
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setZ(tmp_value);
    }
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:w"), Node());
    if (!triple.is_valid())
        return false;
    {
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setW(tmp_value);
    }
    return true;
} 

template<>
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
    triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "vom:quantityKind"), Curie(ctx.model.world(), "vom:Length"));
    if (!triple.is_valid())
        return false;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector3D"));
    if (!triple.is_valid())
        return false;

    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:x"), Node());
    if (!triple.is_valid())
        return false;
    {
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setX(tmp_value);
    }
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:y"), Node());
    if (!triple.is_valid())
        return false;
    {
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setY(tmp_value);
    }
    triple = Arvida::RDF::find_triple(ctx.model, _b0, Curie(ctx.model.world(), "maths:z"), Node());
    if (!triple.is_valid())
        return false;
    {
        float tmp_value;
        if (!Arvida::RDF::fromRDF(ctx, triple.object, tmp_value))
            return false;
        value.setZ(tmp_value);
    }
    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Segment &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Joint &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "skel:Joint"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;

    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Bone &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "skel:Bone"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;
    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Skeleton &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "skel:Skeleton"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;
    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::SkeletonTrackingService &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;

    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "service:SkeletonTrackingService"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;
    return true;
}

template<>
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::TrackingServiceProvider &value)
{
    using namespace Sord;
    Arvida::RDF::Triple triple;
    triple = Arvida::RDF::find_triple(ctx.model, _this0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "core:TrackingServiceProvider"));
    if (!triple.is_valid())
        return false;
    const Node _this = triple.subject;
    return true;
}

} // namespace Arvida
} // namespace RDF

#endif
