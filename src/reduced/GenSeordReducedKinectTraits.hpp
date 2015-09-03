#ifndef KINECT_TRAITS
#define KINECT_TRAITS

#include "SeordRDFTraits.hpp"
#include "ReducedKinect.hpp"
#include "ReducedKinectUtils.hpp"

namespace Arvida
{
namespace RDF
{
/*
inline PathType pathTypeOf_impl(const Context &ctx, const ::Quantity &value)
{
    return RELATIVE_TO_BASE_PATH;
}

inline std::string pathOf_impl(const Context &ctx, const ::Quantity &value)
{
    return uidOf(ctx, value);
}


template<>
inline PathType pathTypeOf(const Context &ctx, const ::QuantityManager &value)
{
    return RELATIVE_TO_BASE_PATH;
}

template<>
inline std::string pathOf(const Context &ctx, const ::QuantityManager &value)
{
    return uidOf(ctx, value);
}
*/

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

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), that_node);

         }
     }
     // Serialize member getY
     {
         const auto & _that = value.getY();
         if (Arvida::RDF::isValidValue(_that))
         {

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), that_node);


         }
     }
     // Serialize member getZ
     {
         const auto & _that = value.getZ();
         if (Arvida::RDF::isValidValue(_that))
         {

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), that_node);


         }
     }
     // Serialize member getW
     {
         const auto & _that = value.getW();
         if (Arvida::RDF::isValidValue(_that))
         {

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

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

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), that_node);


         }
     }
     // Serialize member getY
     {
         const auto & _that = value.getY();
         if (Arvida::RDF::isValidValue(_that))
         {

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), that_node);


         }
     }
     // Serialize member getZ
     {
         const auto & _that = value.getZ();
         if (Arvida::RDF::isValidValue(_that))
         {

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), that_node);


         }
     }



    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::QuantityManager &value)
{
     {


          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "core:Container"));


     }
     // Serialize member getQuantities
     {
         const auto & _that = value.getQuantities();
         if (Arvida::RDF::isValidValue(_that))
         {





         for (auto it = std::begin(_that); it != std::end(_that); ++it)
         {
             const auto & _element = *it;

             Node element_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _element, Arvida::RDF::NO_PATH, ""));


          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "core:member"), element_node);

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
     // Serialize member getQuantityManager
     {
         const auto & _that = value.getQuantityManager();
         if (Arvida::RDF::isValidValue(_that))
         {

         Sord::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "service:trackerQuantities"), that_node);


         }
     }
    return _this;
}


} // namespace Arvida
} // namespace RDF

#endif
