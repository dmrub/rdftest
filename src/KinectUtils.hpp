/*
 * KinectUtils.hpp
 *
 *  Created on: May 23, 2015
 *      Author: Dmitri Rubinstein
 */

#ifndef KINECTUTILS_HPP_INCLUDED
#define KINECTUTILS_HPP_INCLUDED

#ifdef SEORD_LIB
#include "SeordRDFTraits.hpp"
#elif defined(REDLAND_LIB)
#include "RedlandRDFTraits.hpp"
#else
#error "No library specified"
#endif

class PathManager
{
public:

    std::string base_path;

    PathManager(const std::string &base_path) : base_path(base_path) { }

};

std::string get_segments_path(const Arvida::RDF::Context &ctx)
{
    return reinterpret_cast<const PathManager*>(ctx.user_data)->base_path + "/skelTracker/segments";
}

std::string get_coordinate_systems_path(const Arvida::RDF::Context &ctx)
{
    return reinterpret_cast<const PathManager*>(ctx.user_data)->base_path + "/skelTracker/coordinateSystems";
}

std::string get_quantities_path(const Arvida::RDF::Context &ctx)
{
    return reinterpret_cast<const PathManager*>(ctx.user_data)->base_path + "/skelTracker/quantities";
}

namespace Arvida {
namespace RDF {

template <class T>
inline std::string uidOf(const Context &ctx, const std::vector<T> &value)
{
    return "";
}

}
}

#endif /* KINECTUTILS_HPP_INCLUDED */
