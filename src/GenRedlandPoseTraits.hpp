#ifndef POSE_TRAITS
#define POSE_TRAITS

#include "RedlandRDFTraits.hpp"
#include "Pose.hpp"

namespace Arvida
{
namespace RDF
{

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Rotation &value)
{
     Redland::Node _b0 = Redland::Node::make_blank_node(ctx.world); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:Rotation3D"))); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:quantityValue")), _b0); 
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

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Translation &value)
{
     Redland::Node _b0 = Redland::Node::make_blank_node(ctx.world); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:Translation3D"))); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("vom:quantityValue")), _b0); 
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

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Pose &value)
{
     Redland::Node _b1 = Redland::Node::make_blank_node(ctx.world); 
     Redland::Node _b0 = Redland::Node::make_blank_node(ctx.world); 
     {


          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:SpatialRelationship"))); 
          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:LeftHandedCartesianCoordinateSystem3D"))); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:sourceCoordinateSystem")), _b0); 
          ctx.model.add_statement(ctx.world, _b1, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:RightHandedCartesianCoordinateSystem2D"))); 
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:targetCoordinateSystem")), _b1); 


     } 
     // Serialize member getTranslation
     {
         const auto & _that = value.getTranslation();
         if (Arvida::RDF::isValidValue(_that))
         {

         const std::string that_path = ctx.path + "/transl";
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

         const std::string that_path = ctx.path + "/rot";
         Arvida::RDF::Context that_ctx(ctx, that_path);
         Redland::Node that_node(Redland::Node::make_uri_node(ctx.world, that_path));
         if (!Arvida::RDF::isNodeExists(ctx.model, that_node))
             Arvida::RDF::toRDF(that_ctx, that_node, _that);

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("spatial:rotation")), that_node); 


         }
     } 
     
    return _this;
} 

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Device &value)
{
    return _this;
} 


} // namespace Arvida
} // namespace RDF

#endif
