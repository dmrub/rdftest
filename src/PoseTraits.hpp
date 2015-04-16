#ifndef POSE_TRAITS_HPP_INCLUDED
#define POSE_TRAITS_HPP_INCLUDED

#include "RDFTraits.hpp"
#include "Pose.hpp"

#define RDF(x) "http://www.w3.org/1999/02/22-rdf-syntax-ns#" x
#define SPATIAL(x) "http://vocab.arvida.de/2014/03/spatial/vocab#" x
#define TRACKING(x) "http://vocab.arvida.de/2014/03/tracking/vocab#" x
#define MATHS(x) "http://vocab.arvida.de/2014/03/maths/vocab#" x
#define VOM(x) "http://vocab.arvida.de/2014/03/vom/vocab#" x
#define MEA(x) "http://vocab.arvida.de/2014/03/mea/vocab#" x
#define XSD(x) "http://www.w3.org/2001/XMLSchema#" x

namespace Arvida
{
namespace RDF
{

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const double &value)
{
    const SerdNode val = serd_node_new_decimal(value, 7);
    const SerdNode type = serd_node_from_string(SERD_URI, (const uint8_t*) SORD_NS_XSD "double");

    _this = Sord::Node(ctx.model.world(),
        sord_node_from_serd_node(ctx.model.world().c_obj(), ctx.model.world().prefixes().c_obj(), &val, &type, NULL),
        false);
    return _this;
}

inline Sord::Node double_node(Sord::World& world, double d)
{
    const SerdNode val = serd_node_new_decimal(d, 7);
    const SerdNode type = serd_node_from_string(SERD_URI, (const uint8_t*) SORD_NS_XSD "double");

    return Sord::Node(world, sord_node_from_serd_node(world.c_obj(), world.prefixes().c_obj(), &val, &type, NULL),
        false);
}

template<>
NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Translation &value)
{
    using namespace Sord;

    {
        // translation
        Node _b2 = Node::blank_id(ctx.model.world());

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"),
            Curie(ctx.model.world(), "spatial:Translation3D"));

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "vom:quantityValue"), _b2);

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector3D"));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:x"), double_node(ctx.model.world(), value.getX()));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:y"), double_node(ctx.model.world(), value.getY()));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:z"), double_node(ctx.model.world(), value.getZ()));
    }
    return _this;
}

template<>
NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Rotation &value)
{
    using namespace Sord;

    {
        // rotation
        Node _b2 = Node::blank_id(ctx.model.world());

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"),
            Curie(ctx.model.world(), "spatial:Rotation3D"));

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "vom:quantityValue"), _b2);

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector4D"));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "rdf:type"),
            Curie(ctx.model.world(), "maths:Quaternion"));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:x"), Arvida::RDF::toRDF(ctx, value.getX()));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:y"), Arvida::RDF::toRDF(ctx, value.getY()));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:z"), Arvida::RDF::toRDF(ctx, value.getZ()));

        ctx.model.add_statement(_b2, Curie(ctx.model.world(), "maths:w"), Arvida::RDF::toRDF(ctx, value.getW()));

    }
    return _this;
}

template<>
NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Pose &value)
{
    using namespace Sord;

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"),
        Curie(ctx.model.world(), "spatial:SpatialRelationship"));

    // sourceCoordinateSystem
    {
        Node n1 = Node::blank_id(ctx.model.world());

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), n1);

        ctx.model.add_statement(n1, Curie(ctx.model.world(), "rdf:type"),
            Curie(ctx.model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));
    }

    // targetCoordinateSystem
    {
        Node n1 = Node::blank_id(ctx.model.world());

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), n1);

        ctx.model.add_statement(n1, Curie(ctx.model.world(), "rdf:type"),
            Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));
    }

    // translation

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:translation"),
        Arvida::RDF::toRDF(ctx, value.getTranslation()));

    // rotation

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:rotation"),
        Arvida::RDF::toRDF(ctx, value.getRotation()));

    return _this;
}

} // namespace Arvida
} // namespace RDF

#endif
