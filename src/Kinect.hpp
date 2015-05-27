#ifndef KINECT_EXAMPLE
#define KINECT_EXAMPLE

#include <vector>
#include <memory>
#include <utility>
#include "arvida_pp_annotation.h"

#include "visitor/Visitor.hpp"
#include "visitor/Visitable.hpp"

arvida_global_annotation(
    arvida_include("Kinect.hpp"),
    arvida_include("KinectUtils.hpp"),
    arvida_prolog("#ifndef KINECT_TRAITS"),
    arvida_prolog("#define KINECT_TRAITS"),
    arvida_prolog(""),
    arvida_epilog(""),
    arvida_epilog("#endif")
)

// CoordinateSystem

class

RdfUseVisitor()
RdfStmt($this, "rdf:type", "maths:CoordinateSystem")

CoordinateSystem : public Visitable<CoordinateSystem>
{
public:
    META_BaseVisitable(CoordinateSystem)
public:

    CoordinateSystem(const std::string &name) : name_(name) { }

    const std::string & getName() const { return name_; }

    virtual ~CoordinateSystem() { }

private:
    std::string name_;
};

// RightHandedCartesianCoordinateSystem3D

class

RdfStmt($this, "rdf:type", "maths:RightHandedCartesianCoordinateSystem3D")

RightHandedCartesianCoordinateSystem3D : public CoordinateSystem
{
public:
    META_Visitable(RightHandedCartesianCoordinateSystem3D, CoordinateSystem)

    RightHandedCartesianCoordinateSystem3D(const std::string &name) : CoordinateSystem(name) { }

private:
};

// Pose

class

RdfUseVisitor()

Pose: public Visitable<Pose>
{
public:
    META_BaseVisitable(Pose)
public:

    Pose(const std::string &name) : name_(name) { }

    const std::string & getName() const { return name_; }

    virtual ~Pose() { }

private:
    std::string name_;
};

// Rotation

class

RdfStmt($this, "rdf:type", "spatial:Rotation3D")
RdfStmt($this, "vom:quantityValue", _:2)
RdfStmt($this, "vom:quantityKind", "vom:Angle")
RdfStmt(_:2, "rdf:type", "maths:Vector4D")
RdfStmt(_:2, "rdf:type", "maths:Quaternion")

Rotation: public Pose
{
public:

    META_Visitable(Rotation, Pose)

    Rotation(const std::string &name)
        : Pose(name)
        , rotation_{0.0f, 0.0f, 0.0f, 0.0f}
    { }

    Rotation(const std::string &name, float x, float y, float z, float w)
        : Pose(name)
        , rotation_{x, y, z, w}
    { }

    Rotation(const Rotation &other)
        : Pose(other.getName())
        , rotation_{other.rotation_[0], other.rotation_[1], other.rotation_[2], other.rotation_[3]}
    { }

    RdfStmt(_:2, "maths:x", $that)
    float getX() const  { return rotation_[0]; }

    RdfStmt(_:2, "maths:y", $that)
    float getY() const { return rotation_[1]; }

    RdfStmt(_:2, "maths:z", $that)
    float getZ() const { return rotation_[2]; }

    RdfStmt(_:2, "maths:w", $that)
    float getW() const { return rotation_[3]; }

    RdfStmt(_:2, "maths:x", $that)
    void setX(float x) { rotation_[0] = x; }

    RdfStmt(_:2, "maths:y", $that)
    void setY(float y) { rotation_[1] = y; }

    RdfStmt(_:2, "maths:z", $that)
    void setZ(float z) { rotation_[2] = z; }

    RdfStmt(_:2, "maths:w", $that)
    void setW(float w) { rotation_[3] = w; }

private:
    float rotation_[ 4 ] ;
};

// Translation

class

RdfStmt($this, "rdf:type", "spatial:Translation3D")
RdfStmt($this, "vom:quantityValue", _:2)
RdfStmt($this, "vom:quantityKind", "vom:Length")
RdfStmt(_:2, "rdf:type", "maths:Vector3D")

Translation: public Pose
{
public:

    META_Visitable(Translation, Pose)

    Translation(const std::string &name)
        : Pose(name)
        , translation_{0.0f, 0.0f, 0.0f}
    { }

    Translation(const std::string &name, float x, float y, float z)
        : Pose(name)
        , translation_{x, y, z}
    { }

    Translation(const Translation &other)
        : Pose(other.getName())
        , translation_{other.translation_[0], other.translation_[1], other.translation_[2]}
    { }

    RdfStmt(_:2, "maths:x", $that)
    float getX() const  { return translation_[0]; }

    RdfStmt(_:2, "maths:y", $that)
    float getY() const { return translation_[1]; }

    RdfStmt(_:2, "maths:z", $that)
    float getZ() const { return translation_[2]; }

    RdfStmt(_:2, "maths:x", $that)
    void setX(float x) { translation_[0] = x; }

    RdfStmt(_:2, "maths:y", $that)
    void setY(float y) { translation_[1] = y; }

    RdfStmt(_:2, "maths:z", $that)
    void setZ(float z) { translation_[2] = z; }

private:
    float translation_[ 3 ] ;
};

// Segment

class

RdfUseVisitor()

Segment : public Visitable<Segment>
{
public:
    META_BaseVisitable(Segment)
public:

    Segment(const std::string &name) : name_(name) { }

    virtual ~Segment() { }

    const std::string & getName() const { return name_; }

    RdfStmt($this, "spatial:sourceCoordinateSystem", $that)
    RdfAbsolutePath("{::get_coordinate_systems_path($ctx)}/{$that ? $that->getName() : \"\"}")
    const std::shared_ptr< CoordinateSystem > & getSourceCoordinateSystem() const { return sourceCoordinateSystem_; }

    void setSourceCoordinateSystem(const std::shared_ptr< CoordinateSystem > & sourceCoordinateSystem) { sourceCoordinateSystem_ = sourceCoordinateSystem; }

    RdfStmt($this, "spatial:targetCoordinateSystem", $that)
    RdfAbsolutePath("{::get_coordinate_systems_path($ctx)}/{$that ? $that->getName() : \"\"}")
    const std::shared_ptr< CoordinateSystem > & getTargetCoordinateSystem() const { return targetCoordinateSystem_; }

    void setTargetCoordinateSystem(const std::shared_ptr< CoordinateSystem > & targetCoordinateSystem) { targetCoordinateSystem_ = targetCoordinateSystem; }

    RdfStmt($this, "spatial:translation", $that)
    RdfAbsolutePath("{::get_poses_path($ctx)}/{$that ? $that->getName() : \"\"}")
    const std::shared_ptr< Translation > & getTranslation() const { return translation_; }

    void setTranslation(const std::shared_ptr< Translation > & translation) { translation_ = translation; }

    RdfStmt($this, "spatial:rotation", $that)
    RdfAbsolutePath("{::get_poses_path($ctx)}/{$that ? $that->getName() : \"\"}")
    const std::shared_ptr< Rotation > & getRotation() const { return rotation_; }

    void setRotation(const std::shared_ptr< Rotation > & rotation) { rotation_ = rotation; }

private:
    std::shared_ptr< CoordinateSystem > sourceCoordinateSystem_;
    std::shared_ptr< CoordinateSystem > targetCoordinateSystem_;
    std::shared_ptr< Translation > translation_;
    std::shared_ptr< Rotation > rotation_;
    std::string name_;
};

// Joint

class

RdfStmt($this, "rdf:type", "skel:Joint")

Joint: public Segment
{
public:
    META_Visitable(Joint, Segment)
public:
    Joint(const std::string &name) : Segment(name) { }
};

// Bone

class

RdfStmt($this, "rdf:type", "skel:Bone")

Bone: public Segment
{
public:
    META_Visitable(Joint, Segment)
public:

    Bone(const std::string &name)
        : Segment(name)
        , startJoint_()
        , endJoint_()
    { }

    RdfStmt($this, "skel:startJoint", $that)
    const std::shared_ptr< Joint > & getStartJoint() const { return startJoint_; }

    void setStartJoint(const std::shared_ptr< Joint > & startJoint) { startJoint_ = startJoint; }

    RdfStmt($this, "skel:endJoint", $that)
    const std::shared_ptr< Joint > & getEndJoint() const { return endJoint_; }

    void setEndJoint(const std::shared_ptr< Joint > & endJoint) { endJoint_ = endJoint; }

private:
    std::shared_ptr< Joint > startJoint_;
    std::shared_ptr< Joint > endJoint_;
};

// Skeleton

class

RdfStmt($this, "rdf:type", "skel:Skeleton")

Skeleton
{
public:

    Skeleton(const std::string &name) : name_(name) { }

    const std::string & getName() const { return name_; }

    RdfAbsoluteElementPath("{::get_segments_path($ctx)}/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "skel:skeletonBone", $that.foreach)
    const std::vector< std::shared_ptr<Bone> > & getBones() const { return bones_; }

    void setBones(const std::vector< std::shared_ptr<Bone> > & bones)
    {
        bones_ = bones;
    }

    void setBones(std::vector< std::shared_ptr<Bone> > && bones)
    {
        bones_ = std::move(bones);
    }

    RdfAbsoluteElementPath("{::get_segments_path($ctx)}/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "skel:skeletonJoint", $that.foreach)
    const std::vector< std::shared_ptr<Joint> > & getJoints() const { return joints_; }

    void setJoints(const std::vector< std::shared_ptr<Joint> > & joints)
    {
        joints_ = joints;
    }

    void setJoints(std::vector< std::shared_ptr<Joint> > && joints)
    {
        joints_ = std::move(joints);
    }

    RdfAbsoluteElementPath("{::get_segments_path($ctx)}/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "skel:skeletonRoot", $that.foreach)
    const std::vector< std::shared_ptr<Segment> > & getRoots() const { return roots_; }
    void setRoots(const std::vector< std::shared_ptr<Segment> > &roots) { roots_ = roots; }

private:
    std::string name_;
    std::vector< std::shared_ptr<Bone> > bones_;
    std::vector< std::shared_ptr<Joint> > joints_;
    std::vector< std::shared_ptr<Segment> > roots_;
};

// SkeletonTrackingService

class

RdfStmt($this, "rdf:type", "service:SkeletonTrackingService")

SkeletonTrackingService
{
public:

    SkeletonTrackingService()
        : coordinateSystems_()
        , poses_()
        , segments_()
        , skeletons_()
    { }

    RdfPath("/coordinateSystems/")
    RdfElementPath("/coordinateSystems/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "service:trackerCoordinateSystems", $that)
    RdfStmt($that, "rdf:type", "core:Container")
    RdfStmt($that, "core:member", $that.foreach)
    const std::vector< std::shared_ptr<CoordinateSystem> > & getCoordinateSystems() const
    {
        return coordinateSystems_;
    }

    void setCoordinateSystems(const std::vector< std::shared_ptr<CoordinateSystem> > & coordinateSystems)
    {
        coordinateSystems_ = coordinateSystems;
    }

    void setCoordinateSystems(std::vector< std::shared_ptr<CoordinateSystem> > && coordinateSystems )
    {
        coordinateSystems_ = std::move(coordinateSystems);
    }

    RdfPath("/poses/")
    RdfElementPath("/poses/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "service:trackerPoses", $that)
    RdfStmt($that, "rdf:type", "core:Container")
    RdfStmt($that, "core:member", $that.foreach)
    const std::vector< std::shared_ptr<Pose> > & getPoses() const
    {
        return poses_;
    }

    void setPoses(const std::vector< std::shared_ptr<Pose> > & poses)
    {
        poses_ = poses;
    }

    void setPoses(std::vector< std::shared_ptr<Pose> > && poses )
    {
        poses_ = std::move(poses);
    }

    RdfPath("/segments/")
    RdfElementPath("/segments/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "service:trackerSegments", $that)
    RdfStmt($that, "rdf:type", "core:Container")
    RdfStmt($that, "core:member", $that.foreach)
    const std::vector< std::shared_ptr<Segment> > & getSegments() const
    {
        return segments_;
    }

    void setSegments(const std::vector< std::shared_ptr<Segment> > & segments)
    {
        segments_ = segments;
    }

    void setSegments(std::vector< std::shared_ptr<Segment> > && segments )
    {
        segments_ = std::move(segments);
    }

    RdfPath("/skeletons/")
    RdfElementPath("/skeletons/{$element ? $element->getName() : \"\"}")
    RdfStmt($this, "service:trackerSkeletons", $that)
    RdfStmt($that, "rdf:type", "core:Container")
    RdfStmt($that, "core:member", $that.foreach)
    const std::vector< std::shared_ptr<Skeleton> > & getSkeletons() const
    {
        return skeletons_;
    }

    void setSkeletons(const std::vector< std::shared_ptr<Skeleton> > & skeletons)
    {
        skeletons_ = skeletons;
    }

    void setSkeletons(std::vector< std::shared_ptr<Skeleton> > && skeletons )
    {
        skeletons_ = std::move(skeletons);
    }

private:
    std::vector< std::shared_ptr<CoordinateSystem> > coordinateSystems_;
    std::vector< std::shared_ptr<Pose> > poses_;
    std::vector< std::shared_ptr<Segment> > segments_;
    std::vector< std::shared_ptr<Skeleton> > skeletons_;
};

class
RdfStmt($this, "rdf:type", "core:TrackingServiceProvider")
TrackingServiceProvider
{
public:

    RdfPath("/skelTracker")
    RdfStmt($this, "core:service", $that)
    const SkeletonTrackingService & getSkeletonTracker() const { return skeletonTracker_; }

    SkeletonTrackingService & getSkeletonTracker() { return skeletonTracker_; }

private:
    SkeletonTrackingService skeletonTracker_;
};

#endif
