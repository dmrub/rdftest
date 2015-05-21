/*
 * KinectTraits.hpp
 *
 *  Created on: May 20, 2015
 *      Author: Dmitri Rubinstein
 */

#ifndef KINECTTRAITS_HPP_INCLUDED
#define KINECTTRAITS_HPP_INCLUDED

#include "GenKinectTraits.hpp"

namespace Arvida
{
namespace RDF
{

class CoordinateSystemVisitor : public Visitor<const CoordinateSystem, NodeRef, const Context &, NodeRef>
{
public:
    META_Visitor(CoordinateSystemVisitor, toRDF)

    CoordinateSystemVisitor()
    {
        // Set visitables classes (no need to specify base class)
        META_Visitables(RightHandedCartesianCoordinateSystem3D);
    }

protected:
    NodeRef toRDF(const CoordinateSystem & cs, const Context &ctx, NodeRef _this)
    {
        return toRDF_impl(ctx, _this, cs);
    }

    NodeRef toRDF(const RightHandedCartesianCoordinateSystem3D & cs, const Context &ctx, NodeRef _this)
    {
        return toRDF_impl(ctx, _this, cs);
    }
};

template <>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::CoordinateSystem &value)
{
    CoordinateSystemVisitor v;
    return v(value, ctx, _this);
}

class SegmentVisitor : public Visitor<const Segment, NodeRef, const Context &, NodeRef>
{
public:
    META_Visitor(SegmentVisitor, toRDF)

    SegmentVisitor()
    {
        // Set visitables classes (no need to specify base class)
        META_Visitables(Joint, Bone);
    }

protected:
    NodeRef toRDF(const Segment & cs, const Context &ctx, NodeRef _this)
    {
        return toRDF_impl(ctx, _this, cs);
    }

    NodeRef toRDF(const Joint & cs, const Context &ctx, NodeRef _this)
    {
        return toRDF_impl(ctx, _this, cs);
    }

    NodeRef toRDF(const Bone & cs, const Context &ctx, NodeRef _this)
    {
        return toRDF_impl(ctx, _this, cs);
    }

};

template <>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Segment &value)
{
    SegmentVisitor v;
    return v(value, ctx, _this);
}

template <>
inline NodeRef toRDF(const Context &ctx, NodeRef _this, const ::Joint &value)
{
    return toRDF(ctx, _this, static_cast<const ::Segment &>(value));
}

}
}

#endif /* KINECTTRAITS_HPP_INCLUDED */