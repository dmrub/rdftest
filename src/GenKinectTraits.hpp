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
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:CoordinateSystem"));

    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::RightHandedCartesianCoordinateSystem3D &value)
{
    toRDF_impl(ctx, _this, static_cast<const ::CoordinateSystem &>(value));
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:RightHandedCartesianCoordinateSystem3D"));

    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Pose &value)
{
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Rotation &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Pose &>(value));
    Node _b0 = Node::blank_id(ctx.model.world());
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:Rotation3D"));

    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityValue"), _b0);

    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityKind"), Sord::Curie(ctx.model.world(), "vom:Angle"));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Vector4D"));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Quaternion"));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), Arvida::RDF::toRDF(ctx, value.getX()));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), Arvida::RDF::toRDF(ctx, value.getY()));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), Arvida::RDF::toRDF(ctx, value.getZ()));

    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:w"), Arvida::RDF::toRDF(ctx, value.getW()));

    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Translation &value)
{
     toRDF_impl(ctx, _this, static_cast<const ::Pose &>(value));
    Node _b0 = Node::blank_id(ctx.model.world());
    {
        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "spatial:Translation3D"));

        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityValue"), _b0);

        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "vom:quantityKind"), Sord::Curie(ctx.model.world(), "vom:Length"));

        ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "rdf:type"), Sord::Curie(ctx.model.world(), "maths:Vector3D"));
    }
    {
    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:x"), Arvida::RDF::toRDF(ctx, value.getX()));
    }
    {
    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:y"), Arvida::RDF::toRDF(ctx, value.getY()));
    }
    {
    ctx.model.add_statement(_b0, Sord::Curie(ctx.model.world(), "maths:z"), Arvida::RDF::toRDF(ctx, value.getZ()));
    }
    return _this;
}

inline NodeRef toRDF_impl(const Context &ctx, NodeRef _this, const ::Segment &value)
{
    // Serialize member getSourceCoordinateSystem
    {
        const auto & _that = value.getSourceCoordinateSystem();
        const std::string path_3 = (::get_coordinate_systems_path(ctx)) + "/" + (_that ? _that->getName() : "");
        Arvida::RDF::Context ctx_3(ctx, path_3);
        Sord::URI node_3(ctx.model.world(), path_3);
        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:sourceCoordinateSystem"), Arvida::RDF::toRDF(ctx_3, node_3, _that));
    }
    {
        const auto & _that = value.getTargetCoordinateSystem();
        const std::string path_7 = (::get_coordinate_systems_path(ctx)) + "/" + (_that ? _that->getName() : "");
        Arvida::RDF::Context ctx_7(ctx, path_7);
        Sord::URI node_7(ctx.model.world(), path_7);
        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:targetCoordinateSystem"), Arvida::RDF::toRDF(ctx_7, node_7, _that));
    }

    if (true && true && value.getTranslation())
    {
        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:translation"), Arvida::RDF::toRDF(ctx, value.getTranslation()));
    }

    if (true && true && value.getRotation())
    {
        ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "spatial:rotation"), Arvida::RDF::toRDF(ctx, value.getRotation()));
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
    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:startJoint"), Arvida::RDF::toRDF(ctx, value.getStartJoint()));

    ctx.model.add_statement(_this, Sord::Curie(ctx.model.world(), "skel:endJoint"), Arvida::RDF::toRDF(ctx, value.getEndJoint()));

    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Skeleton &value)
{
    using namespace Sord;
    ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "skel:Skeleton"));

    {
        const auto & _container = value.getBones();
        for (auto it = std::begin(_container); it != std::end(_container); ++it)
        {
            const auto & _that = *it;
        const std::string path_7 = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
            Arvida::RDF::Context ctx_7(ctx, path_7);
            Sord::URI node_7(ctx.model.world(), path_7);
            ctx.model.add_statement(_this, Curie(ctx.model.world(), "skel:skeletonBone"), Arvida::RDF::toRDF(ctx_7, node_7, _that));
        }
    }
    {
        const auto & _container = value.getJoints();
        for (auto it = std::begin(_container); it != std::end(_container); ++it)
        {
            const auto & _that = *it;
        const std::string path_11 = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
            Arvida::RDF::Context ctx_11(ctx, path_11);
            Sord::URI node_11(ctx.model.world(), path_11);
            ctx.model.add_statement(_this, Curie(ctx.model.world(), "skel:skeletonJoint"), Arvida::RDF::toRDF(ctx_11, node_11, _that));
        }
    }
    {
        const auto & _container = value.getRoots();
        for (auto it = std::begin(_container); it != std::end(_container); ++it)
        {
            const auto & _that = *it;
        const std::string path_15 = (::get_segments_path(ctx)) + "/" + (_that ? _that->getName() : "");
            Arvida::RDF::Context ctx_15(ctx, path_15);
            Sord::URI node_15(ctx.model.world(), path_15);
            ctx.model.add_statement(_this, Curie(ctx.model.world(), "skel:skeletonRoot"), Arvida::RDF::toRDF(ctx_15, node_15, _that));
        }
    }
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::SkeletonTrackingService &value)
{
    using namespace Sord;
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "service:SkeletonTrackingService"));

    {
        const auto & _that = value.getCoordinateSystems();
        const std::string path_7 = ctx.path + "/coordinateSystems/";
        Arvida::RDF::Context ctx_7(ctx, path_7);
        Sord::URI node_7(ctx.model.world(), path_7);

        ctx.model.add_statement(_this, Curie(ctx.model.world(), "service:trackerCoordinateSystems"), node_7);

        ctx.model.add_statement(node_7, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "core:Container"));

        for (auto it = std::begin(_that); it != std::end(_that); ++it)
        {
            const auto & _that = *it;
            const std::string path_15 = ctx.path + "/coordinateSystems/" + (_that ? _that->getName() : "");
            Arvida::RDF::Context ctx_15(ctx, path_15);
            Sord::URI node_15(ctx.model.world(), path_15);
            ctx.model.add_statement(node_7, Curie(ctx.model.world(), "core:member"), Arvida::RDF::toRDF(ctx_15, node_15, _that));
        }
    }

    {
        const auto & _that = value.getPoses();
        const std::string path_11 = ctx.path + "/poses/";
        Arvida::RDF::Context ctx_11(ctx, path_11);
        Sord::URI node_11(ctx.model.world(), path_11);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "service:trackerPoses"), Arvida::RDF::toRDF(ctx_11, node_11, _that));
    }
    {
        const auto & _that = value.getSegments();
        const std::string path_15 = ctx.path + "/segments/";
        Arvida::RDF::Context ctx_15(ctx, path_15);
        Sord::URI node_15(ctx.model.world(), path_15);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "service:trackerSegments"), Arvida::RDF::toRDF(ctx_15, node_15, _that));
    }
    {
        const auto & _that = value.getSkeletons();
        const std::string path_19 = ctx.path + "/skeletons/";
        Arvida::RDF::Context ctx_19(ctx, path_19);
        Sord::URI node_19(ctx.model.world(), path_19);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "service:trackerSkeletons"), Arvida::RDF::toRDF(ctx_19, node_19, _that));
    }
    return _this;
}

template<>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::TrackingServiceProvider &value)
{
    using namespace Sord;
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "rdf:type"), Curie(ctx.model.world(), "core:TrackingServiceProvider"));

    {
        const auto & _that = value.getSkeletonTracker();
        const std::string path_7 = ctx.path + "/skelTracker";
        Arvida::RDF::Context ctx_7(ctx, path_7);
        Sord::URI node_7(ctx.model.world(), path_7);
        ctx.model.add_statement(_this, Curie(ctx.model.world(), "core:service"), Arvida::RDF::toRDF(ctx_7, node_7, _that));
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
inline bool fromRDF(const Context &ctx, const NodeRef _this0, ::Pose &value)
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
