#ifndef REDUCED_KINECT_EXAMPLE
#define REDUCED_KINECT_EXAMPLE

#include <vector>
#include <memory>
#include <utility>
#include "arvida_pp_annotation.h"

#include "visitor/Visitor.hpp"
#include "visitor/Visitable.hpp"

arvida_global_annotation(
    arvida_include("ReducedKinect.hpp"),
    arvida_include("ReducedKinectUtils.hpp"),
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

// Quantity

class

RdfUseVisitor()
RdfPath("{$this->getName()}")

Quantity: public Visitable<Quantity>
{
public:
    META_BaseVisitable(Quantity)
public:

    Quantity(const std::string &name) : name_(name) { }

    const std::string & getName() const { return name_; }

    virtual ~Quantity() { }

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

Rotation: public Quantity
{
public:

    META_Visitable(Rotation, Quantity)

    Rotation(const std::string &name)
        : Quantity(name)
        , rotation_{0.0f, 0.0f, 0.0f, 0.0f}
    { }

    Rotation(const std::string &name, float x, float y, float z, float w)
        : Quantity(name)
        , rotation_{x, y, z, w}
    { }

    Rotation(const Rotation &other)
        : Quantity(other.getName())
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

Translation: public Quantity
{
public:

    META_Visitable(Translation, Quantity)

    Translation(const std::string &name)
        : Quantity(name)
        , translation_{0.0f, 0.0f, 0.0f}
    { }

    Translation(const std::string &name, float x, float y, float z)
        : Quantity(name)
        , translation_{x, y, z}
    { }

    Translation(const Translation &other)
        : Quantity(other.getName())
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


class

RdfPath("/quantities/")
RdfStmt($this, "rdf:type", "core:Container")

QuantityManager
{
public:

    QuantityManager() { }

    RdfStmt($this, "core:member", $that.foreach)
    const std::vector< std::shared_ptr<Quantity> > & getQuantities() const
    {
        return quantities_;
    }

    void setQuantities(const std::vector< std::shared_ptr<Quantity> > & quantities)
    {
        quantities_ = quantities;
    }

    void setQuantities(std::vector< std::shared_ptr<Quantity> > && quantities )
    {
        quantities_ = std::move(quantities);
    }

private:
    std::vector< std::shared_ptr<Quantity> > quantities_;
};

// SkeletonTrackingService

class

RdfStmt($this, "rdf:type", "service:SkeletonTrackingService")

SkeletonTrackingService
{
public:

    SkeletonTrackingService()
        : quantityManager_()
    { }

    RdfStmt($this, "service:trackerQuantities", $that)
    const QuantityManager & getQuantityManager() const
    {
        return quantityManager_;
    }

    QuantityManager & getQuantityManager()
    {
        return quantityManager_;
    }

private:
    QuantityManager quantityManager_;
};

#endif
