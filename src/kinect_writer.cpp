/*
 * kinect_writer.cpp
 *
 *  Created on: 18 May, 2015
 *      Author: Dmitri Rubinstein
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdarg.h>
#include <string>
#include <iostream>

#include "sord/sordmm.hpp"
#include "serd/serd.h"
#include "KinectTraits.hpp"


#define RDF(x) "http://www.w3.org/1999/02/22-rdf-syntax-ns#" x
#define SPATIAL(x) "http://vocab.arvida.de/2014/03/spatial/vocab#" x
#define TRACKING(x) "http://vocab.arvida.de/2014/03/tracking/vocab#" x
#define MATHS(x) "http://vocab.arvida.de/2014/03/maths/vocab#" x
#define VOM(x) "http://vocab.arvida.de/2014/03/vom/vocab#" x
#define MEA(x) "http://vocab.arvida.de/2014/03/mea/vocab#" x
#define XSD(x) "http://www.w3.org/2001/XMLSchema#" x
#define SKEL(x) "http://vocab.arvida.de/2015/05/skel/vocab#" x
#define SERVICE(x) "http://vocab.arvida.de/2015/05/skelTracker/vocab#" x
#define CORE(x) "http://vocab.arvida.de/2014/02/core/vocab#" x

int main(int argc, char *argv[])
{
    using namespace Sord;

    int num = 1;

    if (argc > 1) {
        num = atoi(argv[1]);
    }

    World world;

    world.add_prefix("rdf", RDF(""));
    world.add_prefix("maths", MATHS(""));
    world.add_prefix("spatial", SPATIAL(""));
    world.add_prefix("tracking", TRACKING(""));
    world.add_prefix("vom", VOM(""));
    world.add_prefix("mea", MEA(""));
    world.add_prefix("xsd", XSD(""));
    world.add_prefix("skel", SKEL(""));
    world.add_prefix("service", SERVICE(""));
    world.add_prefix("core", CORE(""));

    Model model(world, "file:///example.com/");

    std::cout << "Producing " << num << " kinect dataset(s)" << std::endl;

    auto leftElbowRotation = std::make_shared<::Rotation>("resc28/leftElbowRotation", 1, 2, 3, 4);
    auto leftLowerArmTranslation = std::make_shared<::Translation>("resc28/leftLowerArmTranslation", 1, 2, 3);
    auto leftUpperArmTranslation = std::make_shared<::Translation>("resc28/leftUpperArmTranslation", 4, 5, 6);

    auto llaCS1 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>("resc28/llaCS1");
    auto llaCS2 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>("resc28/llaCS2");
    auto luaCS1 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>("resc28/luaCS1");
    auto luaCS2 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>("resc28/luaCS2");

    std::vector< std::shared_ptr<::CoordinateSystem> > coordinateSystems;
    coordinateSystems.push_back(llaCS1);
    coordinateSystems.push_back(llaCS2);
    coordinateSystems.push_back(luaCS1);
    coordinateSystems.push_back(luaCS2);

    auto leftElbow = std::make_shared<::Joint>("resc28/leftElbow");
    leftElbow->setTargetCoordinateSystem(llaCS1);
    leftElbow->setSourceCoordinateSystem(luaCS2);
    leftElbow->setRotation(leftElbowRotation);

    auto leftLowerArm = std::make_shared<::Bone>("resc28/leftLowerArm");
    leftLowerArm->setSourceCoordinateSystem(llaCS1);
    leftLowerArm->setTargetCoordinateSystem(llaCS2);
    leftLowerArm->setTranslation(leftLowerArmTranslation);
    leftLowerArm->setStartJoint(leftElbow);

    auto leftUpperArm = std::make_shared<::Bone>("resc28/leftUpperArm");
    leftUpperArm->setSourceCoordinateSystem(luaCS1);
    leftUpperArm->setTargetCoordinateSystem(luaCS2);
    leftUpperArm->setTranslation(leftUpperArmTranslation);
    leftUpperArm->setEndJoint(leftElbow);

    std::vector< std::shared_ptr<Pose> > poses;
    poses.push_back(leftElbowRotation);
    poses.push_back(leftLowerArmTranslation);
    poses.push_back(leftUpperArmTranslation);

    auto resc28 = std::make_shared<::Skeleton>("resc28");
    std::vector< std::shared_ptr<Bone> > bones;
    bones.push_back(leftLowerArm);
    bones.push_back(leftUpperArm);
    resc28->setBones(std::move(bones));

    std::vector< std::shared_ptr<Joint> > joints;
    joints.push_back(leftElbow);

    resc28->setJoints(std::move(joints));

    std::vector< std::shared_ptr<Segment> > roots;
    roots.push_back(leftUpperArm);
    resc28->setRoots(roots);

    std::vector< std::shared_ptr<::Skeleton> > skeletons;
    skeletons.push_back(resc28);

    std::vector< std::shared_ptr<::Segment> > segments;
    segments.push_back(leftLowerArm);
    segments.push_back(leftElbow);
    segments.push_back(leftUpperArm);

    TrackingServiceProvider kinect;
    kinect.getSkeletonTracker().setCoordinateSystems(std::move(coordinateSystems));
    kinect.getSkeletonTracker().setPoses(std::move(poses));
    kinect.getSkeletonTracker().setSegments(std::move(segments));
    kinect.getSkeletonTracker().setSkeletons(std::move(skeletons));

    PathManager pm("file:///example.com");

    {
        Arvida::RDF::Context ctx(model, pm.base_path, &pm);
        URI kinect_node(world, pm.base_path);

        //Arvida::RDF::toRDF(ctx, kinect_node, *leftElbow);
        //Arvida::RDF::toRDF(ctx, kinect_node, resc28);
        Arvida::RDF::toRDF(ctx, kinect_node, kinect);
    }

    std::cout << "Writing poses to kinect_sordmm.ttl" << std::endl;

    model.write_to_file("kinect_sordmm.ttl", SERD_TURTLE,
        (SerdStyle)(SERD_STYLE_ABBREVIATED | SERD_STYLE_CURIED | SERD_STYLE_RESOLVED));


#if 0
    for (int i = 0; i < num; ++i)
    {
        const std::string uuid_url = "file:///example.com/" + std::to_string(i);

        Arvida::RDF::Context ctx(model, uuid_url);

        URI pose_node(world, uuid_url);

        Pose pose(
            Translation(1, 2, 3),
            Rotation(1, 1, 1, 1));

        Arvida::RDF::toRDF(ctx, pose_node, pose);
    }

    std::cout << "Writing poses to pose_sordmm.ttl" << std::endl;

    model.write_to_file("pose_sordmm.ttl", SERD_TURTLE,
        (SerdStyle)(SERD_STYLE_ABBREVIATED | SERD_STYLE_CURIED | SERD_STYLE_RESOLVED));
#endif
    return 0;
}
