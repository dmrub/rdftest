#ifndef KINECT_TRAITS
#define KINECT_TRAITS

#include "Kinect.hpp"
#include "RDFTraits.hpp"

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

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "vom:quantityKind"), Curie(ctx.model.world(), "vom:Angle"));

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

    ctx.model.add_statement(_this, Curie(ctx.model.world(), "vom:quantityKind"), Curie(ctx.model.world(), "vom:Length"));

    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "maths:Vector3D"));

    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:x"), Arvida::RDF::toRDF(ctx, value.getX()));

    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:y"), Arvida::RDF::toRDF(ctx, value.getY()));

    ctx.model.add_statement(_b0, Curie(ctx.model.world(), "maths:z"), Arvida::RDF::toRDF(ctx, value.getZ()));

    return _this;
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

} // namespace Arvida
} // namespace RDF

#endif
