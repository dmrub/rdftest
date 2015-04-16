/*
 * pose_sordmm2.cpp
 *
 *  Created on: Apr 15, 2015
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
#include "Pose.hpp"
#include "PoseTraits.hpp"

#define RDF(x) "http://www.w3.org/1999/02/22-rdf-syntax-ns#" x
#define SPATIAL(x) "http://vocab.arvida.de/2014/03/spatial/vocab#" x
#define TRACKING(x) "http://vocab.arvida.de/2014/03/tracking/vocab#" x
#define MATHS(x) "http://vocab.arvida.de/2014/03/maths/vocab#" x
#define VOM(x) "http://vocab.arvida.de/2014/03/vom/vocab#" x
#define MEA(x) "http://vocab.arvida.de/2014/03/mea/vocab#" x
#define XSD(x) "http://www.w3.org/2001/XMLSchema#" x

#define NEW_URI_NODE(world, uri_str) librdf_new_node_from_uri_string(world, (const unsigned char*)uri_str)
#define NEW_LITERAL_NODE(world, literal_str) librdf_new_node_from_literal(world, (const unsigned char*)literal_str, NULL, 0)
#define NEW_BLANK_NODE(world) librdf_new_node_from_blank_identifier(world, NULL)

inline Sord::Node double_node(Sord::World& world, double d) {
    const SerdNode val  = serd_node_new_decimal(d, 7);
    const SerdNode type = serd_node_from_string(
        SERD_URI, (const uint8_t*)SORD_NS_XSD "double");

    return Sord::Node(
        world,
        sord_node_from_serd_node(
            world.c_obj(), world.prefixes().c_obj(), &val, &type, NULL),
            false);
}

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

    Model model(world, "http://test.arvida.de/");

    Arvida::RDF::Context ctx(model);

    std::cout << "Producing " << num << " poses" << std::endl;

    for (int i = 0; i < num; ++i)
    {
        const std::string uuid_url = "http://test.arvida.de/UUID" + std::to_string(i);

        URI pose_node(world, uuid_url);

        Pose pose(
            Translation(1, 2, 3),
            Rotation(1, 1, 1, 1));

        Arvida::RDF::toRDF(ctx, pose_node, pose);
    }

    std::cout << "Writing poses" << std::endl;

    model.write_to_file("pose_sordmm.ttl", SERD_TURTLE,
        (SerdStyle)(SERD_STYLE_ABBREVIATED | SERD_STYLE_CURIED | SERD_STYLE_RESOLVED));

    return 0;
}
