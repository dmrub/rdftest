#ifndef KINECT_TRAITS
#define KINECT_TRAITS

#include "RedlandRDFTraits.hpp"
#include "ReducedKinect.hpp"
#include "ReducedKinectUtils.hpp"

namespace Arvida
{
namespace RDF
{

inline PathType pathTypeOf_impl(const Context &ctx, const ::Quantity &value)
{
    return RELATIVE_TO_BASE_PATH;
}

inline std::string pathOf_impl(const Context &ctx, const ::Quantity &value)
{
    const auto _this = &value;
    return (_this->getName());
}

template<>
inline PathType pathTypeOf(const Context &ctx, const ::QuantityManager &value)
{
    return RELATIVE_TO_BASE_PATH;
}

template<>
inline std::string pathOf(const Context &ctx, const ::QuantityManager &value)
{
    const auto _this = &value;
    return value.getUId();
}

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

         Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:x")), that_node);

        }
    }
    // Serialize member getY
    {
        const auto & _that = value.getY();
        if (Arvida::RDF::isValidValue(_that))
        {

         Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:y")), that_node);

        }
    }
    // Serialize member getZ
    {
        const auto & _that = value.getZ();
        if (Arvida::RDF::isValidValue(_that))
        {

         Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:z")), that_node);

        }
    }
    // Serialize member getW
    {
        const auto & _that = value.getW();
        if (Arvida::RDF::isValidValue(_that))
        {

         Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

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
            Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:x")), that_node); 
        }
    }
    // Serialize member getY
    {
        const auto & _that = value.getY();
        if (Arvida::RDF::isValidValue(_that))
        {

            Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

            ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:y")), that_node); 

        }
    }
    // Serialize member getZ
    {
        const auto & _that = value.getZ();
        if (Arvida::RDF::isValidValue(_that))
        {

            Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _b0, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("maths:z")), that_node);

        }
    }

    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::QuantityManager &value)
{
    {
          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("rdf:type")), Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:Container")));

    }

    // Serialize member getQuantities
    {
        const auto & _that = value.getQuantities();
        if (Arvida::RDF::isValidValue(_that))
        {



            for (auto it = std::begin(_that); it != std::end(_that); ++it)
            {
                const auto & _element = *it;
             Redland::Node element_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _element, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("core:member")), element_node);

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
     // Serialize member getQuantityManager
     {
         const auto & _that = value.getQuantityManager();
         if (Arvida::RDF::isValidValue(_that))
         {

         Redland::Node that_node(Arvida::RDF::createRDFNodeAndSerialize(ctx, _that, Arvida::RDF::NO_PATH, ""));

          ctx.model.add_statement(ctx.world, _this, Redland::Node::make_uri_node(ctx.world,  ctx.namespaces.expand("service:trackerQuantities")), that_node);


         }
     }
    return _this;
}

} // namespace Arvida
} // namespace RDF

#endif
