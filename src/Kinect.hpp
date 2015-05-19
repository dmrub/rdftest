#ifndef KINECT_EXAMPLE
#define KINECT_EXAMPLE

#include <vector>
#include <memory>
#include <utility>
#include "arvida_pp_annotation.h"

// CoordinateSystem

class

CoordinateSystem
{
public:
    virtual ~CoordinateSystem() { }
};

// RightHandedCartesianCoordinateSystem3D

class RightHandedCartesianCoordinateSystem3D: public CoordinateSystem
{
public:

private:
};

// Pose

class

Pose
{
public:
    virtual ~Pose() { }
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

    Rotation()
        : rotation_{0.0f, 0.0f, 0.0f, 0.0f}
    { }

    Rotation(float x, float y, float z, float w)
        : rotation_{x, y, z, w}
    { }

    Rotation(const Rotation &other)
        : rotation_{other.rotation_[0], other.rotation_[1], other.rotation_[2], other.rotation_[3]}
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

    Translation()
        : translation_{0.0f, 0.0f, 0.0f}
    { }

    Translation(float x, float y, float z)
        : translation_{x, y, z}
    { }

    Translation(const Translation &other)
        : translation_{other.translation_[0], other.translation_[1], other.translation_[2]}
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

class Segment
{
public:

    virtual ~Segment() { }

    const std::shared_ptr< CoordinateSystem > & getSourceCoordinateSystem() { return _sourceCoordinateSystem; }

    void setSourceCoordinateSystem(const std::shared_ptr< CoordinateSystem > & sourceCoordinateSystem) { _sourceCoordinateSystem = sourceCoordinateSystem; }

    const std::shared_ptr< CoordinateSystem > & getTargetCoordinateSystem() { return _targetCoordinateSystem; }

    void setTargetCoordinateSystem(const std::shared_ptr< CoordinateSystem > & targetCoordinateSystem) { _targetCoordinateSystem = targetCoordinateSystem; }

    const std::shared_ptr< Translation > & getTranslation() { return _translation; }

    void setTranslation(const std::shared_ptr< Translation > & translation) { _translation = translation; }

    const std::shared_ptr< Rotation > & getRotation() { return _rotation; }

    void setRotation(const std::shared_ptr< Rotation > & rotation) { _rotation = rotation; }

private:
    std::shared_ptr< CoordinateSystem > _sourceCoordinateSystem;
    std::shared_ptr< CoordinateSystem > _targetCoordinateSystem;
    std::shared_ptr< Translation > _translation;
    std::shared_ptr< Rotation > _rotation;
};

// Joint

class Joint: public Segment
{
public:
    Joint() { }
};

// Bone

class Bone: public Segment
{
public:

    Bone()
        : _startJoint()
        , _endJoint()
    { }

    const std::shared_ptr< Joint > & getStartJoint() { return _startJoint; }

    void setStartJoint(const std::shared_ptr< Joint > & startJoint) { _startJoint = startJoint; }

    const std::shared_ptr< Joint > & getEndJoint() { return _endJoint; }

    void setEndJoint(const std::shared_ptr< Joint > & endJoint) { _endJoint = endJoint; }

private:
    std::shared_ptr< Joint > _startJoint;
    std::shared_ptr< Joint > _endJoint;
};


// Skeleton

class Skeleton
{
public:

    const std::vector< std::shared_ptr<Bone> > & getBones() const { return _bones; }
    void setBones(const std::vector< std::shared_ptr<Bone> > & bones)
    {
        _bones = bones;
    }

    void setBones(std::vector< std::shared_ptr<Bone> > && bones)
    {
        _bones = std::move(bones);
    }

    const std::vector< std::shared_ptr<Joint> > & getJoints() const { return _joints; }
    void setJoints(const std::vector< std::shared_ptr<Joint> > & joints)
    {
        _joints = joints;
    }

    void setJoints(std::vector< std::shared_ptr<Joint> > && joints)
    {
        _joints = std::move(joints);
    }

    const std::vector< std::shared_ptr<Segment> > & getRoots() { return _roots; }
    void setRoots(const std::vector< std::shared_ptr<Segment> > &roots) { _roots = roots; }

private:
    std::vector< std::shared_ptr<Bone> > _bones;
    std::vector< std::shared_ptr<Joint> > _joints;
    std::vector< std::shared_ptr<Segment> > _roots;
};

// SkeletonTrackingService

class SkeletonTrackingService
{
public:

    SkeletonTrackingService()
        : coordinateSystems_()
        , poses_()
        , segments_()
        , skeletons_()
    { }

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

class TrackingServiceProvider
{
public:

    const SkeletonTrackingService & getSkeletonTracker() const { return skeletonTracker_; }

    SkeletonTrackingService & getSkeletonTracker() { return skeletonTracker_; }

private:
    SkeletonTrackingService skeletonTracker_;
};

#endif
