/*
 * KinectUtils.hpp
 *
 *  Created on: May 23, 2015
 *      Author: Dmitri Rubinstein
 */

#ifndef KINECTUTILS_HPP_INCLUDED
#define KINECTUTILS_HPP_INCLUDED

#include "RDFTraits.hpp"

class PathManager
{
public:

    std::string base_path;

    PathManager(const std::string &base_path) : base_path(base_path) { }

};

std::string get_segments_path(const Arvida::RDF::Context &ctx)
{
    return reinterpret_cast<const PathManager*>(ctx.user_data)->base_path + "/kinect/skelTracker/segments";
}

std::string get_coordinate_systems_path(const Arvida::RDF::Context &ctx)
{
    return reinterpret_cast<const PathManager*>(ctx.user_data)->base_path + "/kinect/skelTracker/coordinateSystems";
}

std::string get_poses_path(const Arvida::RDF::Context &ctx)
{
    return reinterpret_cast<const PathManager*>(ctx.user_data)->base_path + "/kinect/skelTracker/poses";
}

#endif /* KINECTUTILS_HPP_INCLUDED */
