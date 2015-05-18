#ifndef KINECT_EXAMPLE
#define KINECT_EXAMPLE

#include <vector>
#include <memory>

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
        : rotation_{0, 0, 0, 0}
    { }

    Rotation(double x, double y, double z, double w)
        : rotation_{x, y, z, w}
    { }

    Rotation(const Rotation &other)
        : rotation_{other.rotation_[0], other.rotation_[1], other.rotation_[2], other.rotation_[3]}
    { }

    RdfStmt(_:2, "maths:x", $that)
    double getX() const  { return rotation_[0]; }

    RdfStmt(_:2, "maths:y", $that)
    double getY() const { return rotation_[1]; }

    RdfStmt(_:2, "maths:z", $that)
    double getZ() const { return rotation_[2]; }

    RdfStmt(_:2, "maths:w", $that)
    double getW() const { return rotation_[3]; }

    RdfStmt(_:2, "maths:x", $that)
    void setX(double x) { rotation_[0] = x; }

    RdfStmt(_:2, "maths:y", $that)
    void setY(double y) { rotation_[1] = y; }

    RdfStmt(_:2, "maths:z", $that)
    void setZ(double z) { rotation_[2] = z; }

    RdfStmt(_:2, "maths:w", $that)
    void setW(double w) { rotation_[3] = w; }

private:
    double rotation_[ 4 ] ;
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
        : translation_{0, 0, 0}
    { }

    Translation(double x, double y, double z)
        : translation_{x, y, z}
    { }

    Translation(const Translation &other)
        : translation_{other.translation_[0], other.translation_[1], other.translation_[2]}
    { }

    RdfStmt(_:2, "maths:x", $that)
    double getX() const  { return translation_[0]; }

    RdfStmt(_:2, "maths:y", $that)
    double getY() const { return translation_[1]; }

    RdfStmt(_:2, "maths:z", $that)
    double getZ() const { return translation_[2]; }

    RdfStmt(_:2, "maths:x", $that)
    void setX(double x) { translation_[0] = x; }

    RdfStmt(_:2, "maths:y", $that)
    void setY(double y) { translation_[1] = y; }

    RdfStmt(_:2, "maths:z", $that)
    void setZ(double z) { translation_[2] = z; }

private:
    double translation_[ 3 ] ;
};

// Segment

class Segment
{
public:

    virtual ~Segment() { }

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
};

// Bone

class Bone: public Segment
{
public:

private:
    std::shared_ptr< Joint > _startJoint;
    std::shared_ptr< Joint > _endJoint;
};


// Skeleton

class Skeleton
{
public:

    const std::vector< std::shared_ptr<Bone> > & getBones() const { return _bones; }
    const std::vector< std::shared_ptr<Joint> > & getJoints() const { return _joints; }
    const std::vector< std::shared_ptr<Segment> > & getRoots() { return _roots; }

private:
    std::vector< std::shared_ptr<Bone> > _bones;
    std::vector< std::shared_ptr<Joint> > _joints;
    std::vector< std::shared_ptr<Segment> > _roots;
};

// SkeletonTrackingService

class SkeletonTrackingService
{
public:

private:
    std::vector< std::shared_ptr< CoordinateSystem > > coordinateSystems_;
    std::vector< std::shared_ptr<Pose> > poses_;
    std::vector< std::shared_ptr<Segment> > segments_;
    std::vector< Skeleton > skeletons_;
};

class TrackingServiceProvider
{
public:

    const SkeletonTrackingService & getSkeletonTracker() const { return skeletonTracker_; }

private:
    SkeletonTrackingService skeletonTracker_;
};

#endif
