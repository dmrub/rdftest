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
#include "Kinect.hpp"

#define RDF(x) "http://www.w3.org/1999/02/22-rdf-syntax-ns#" x
#define SPATIAL(x) "http://vocab.arvida.de/2014/03/spatial/vocab#" x
#define TRACKING(x) "http://vocab.arvida.de/2014/03/tracking/vocab#" x
#define MATHS(x) "http://vocab.arvida.de/2014/03/maths/vocab#" x
#define VOM(x) "http://vocab.arvida.de/2014/03/vom/vocab#" x
#define MEA(x) "http://vocab.arvida.de/2014/03/mea/vocab#" x
#define XSD(x) "http://www.w3.org/2001/XMLSchema#" x

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

    Model model(world, "file:///example.com/");

    std::cout << "Producing " << num << " poses" << std::endl;

    auto leftElbowRotation = std::make_shared<::Rotation>(1, 2, 3, 4);
    auto leftLowerArmTranslation = std::make_shared<::Translation>(1, 2, 3);
    auto leftUpperArmTranslation = std::make_shared<::Translation>(4, 5, 6);

    auto llaCS1 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>();
    auto llaCS2 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>();
    auto luaCS1 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>();
    auto luaCS2 = std::make_shared<::RightHandedCartesianCoordinateSystem3D>();

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
