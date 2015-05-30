#ifndef KINECT_TRAITS
#define KINECT_TRAITS

#include "RedlandRDFTraits.hpp"
#include "Kinect.hpp"
#include "KinectUtils.hpp"

namespace Arvida
{
namespace RDF
{

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::CoordinateSystem &value)
{
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:CoordinateSystem"))); 


     } 
    return _this;
} 

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::RightHandedCartesianCoordinateSystem3D &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::CoordinateSystem &>(value)); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:RightHandedCartesianCoordinateSystem3D"))); 


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
     Redland::Node _b0 = Redland::Node::make_blank_node(ctx.world); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:Rotation3D"))); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:quantityValue")), _b0); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:quantityKind")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:Angle"))); 
          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:Vector4D"))); 
          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:Quaternion"))); 


     } 
     // Serialize member getX
     {
         const auto & _that = value.getX();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:x")), that_node); 


         }
     } 
     // Serialize member getY
     {
         const auto & _that = value.getY();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:y")), that_node); 


         }
     } 
     // Serialize member getZ
     {
         const auto & _that = value.getZ();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:z")), that_node); 


         }
     } 
     // Serialize member getW
     {
         const auto & _that = value.getW();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:w")), that_node); 


         }
     } 
     
     
     
     
    return _this;
} 

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Translation &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Quantity &>(value)); 
     Redland::Node _b0 = Redland::Node::make_blank_node(ctx.world); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:Translation3D"))); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:quantityValue")), _b0); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:quantityKind")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:Length"))); 
          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:Vector3D"))); 


     } 
     // Serialize member getX
     {
         const auto & _that = value.getX();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:x")), that_node); 


         }
     } 
     // Serialize member getY
     {
         const auto & _that = value.getY();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:y")), that_node); 


         }
     } 
     // Serialize member getZ
     {
         const auto & _that = value.getZ();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string &that_path = ctx.path;
         const Arvida::RDF::Context &that_ctx = ctx;
         Redland::Node that_node(Redland::Node::make_blank_node(ctx.world));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:z")), that_node); 


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
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:sourceCoordinateSystem")), that_node); 


         }
     } 
     // Serialize member getTargetCoordinateSystem
     {
         const auto & _that = value.getTargetCoordinateSystem();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_coordinate_systems_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:targetCoordinateSystem")), that_node); 


         }
     } 
     // Serialize member getTranslation
     {
         const auto & _that = value.getTranslation();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_quantities_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:translation")), that_node); 


         }
     } 
     // Serialize member getRotation
     {
         const auto & _that = value.getRotation();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_quantities_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:rotation")), that_node); 


         }
     } 
    return _this;
} 

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Joint &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Segment &>(value)); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:Joint"))); 


     } 
    return _this;
} 

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Bone &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Segment &>(value)); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:Bone"))); 


     } 
     // Serialize member getStartJoint
     {
         const auto & _that = value.getStartJoint();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:startJoint")), that_node); 


         }
     } 
     // Serialize member getEndJoint
     {
         const auto & _that = value.getEndJoint();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:endJoint")), that_node); 


         }
     } 
    return _this;
} 

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Skeleton &value)
{
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:Skeleton"))); 


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
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:skeletonBone")), element_node); 

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
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:skeletonJoint")), element_node); 

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
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("skel:skeletonRoot")), element_node); 

         }
         }
     } 
    return _this;
} 

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::SkeletonTrackingService &value)
{
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("service:SkeletonTrackingService"))); 


     } 
     // Serialize member getCoordinateSystems
     {
         const auto & _that = value.getCoordinateSystems();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/coordinateSystems/";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("service:trackerCoordinateSystems")), that_node); 
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:Container"))); 
      


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/coordinateSystems/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

      
      
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:member")), element_node); 

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
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("service:trackerQuantities")), that_node); 
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:Container"))); 
      


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/quantities/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

      
      
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:member")), element_node); 

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
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("service:trackerSegments")), that_node); 
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:Container"))); 
      


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/segments/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

      
      
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:member")), element_node); 

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
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("service:trackerSkeletons")), that_node); 
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:Container"))); 
      


         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;
             const std::string element_path = ctx.path + "/skeletons/" + (_element ? _element->getName() : "");
             Arvida::RDF::Context element_ctx(ctx, element_path);
             Redland::Node element_node(Redland::Node::make_uri_node(ctx.world, element_path));
             if (!Arvida::RDF::isNodeExists(ctx.model, element_node))
                 Arvida::RDF::toRDF(element_ctx, element_node, _element);

      
      
          ctx.model.add_statement(ctx.world, that_node, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:member")), element_node); 

         }
         }
     } 
    return _this;
} 

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::TrackingServiceProvider &value)
{
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:TrackingServiceProvider"))); 


     } 
     // Serialize member getSkeletonTracker
     {
         const auto & _that = value.getSkeletonTracker();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/skelTracker";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:service")), that_node); 


         }
     } 
    return _this;
} 


} // namespace Arvida
} // namespace RDF

#endif
