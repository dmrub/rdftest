/*
 * pose_redland_writer.cpp
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

#define REDLAND_LIB
#include "redland.hpp"
#include "Pose.hpp"
#include "GenRedlandPoseTraits.hpp"

#define RDF(x) "http://www.w3.org/1999/02/22-rdf-syntax-ns#" x
#define SPATIAL(x) "http://vocab.arvida.de/2014/03/spatial/vocab#" x
#define TRACKING(x) "http://vocab.arvida.de/2014/03/tracking/vocab#" x
#define MATHS(x) "http://vocab.arvida.de/2014/03/maths/vocab#" x
#define VOM(x) "http://vocab.arvida.de/2014/03/vom/vocab#" x
#define MEA(x) "http://vocab.arvida.de/2014/03/mea/vocab#" x
#define XSD(x) "http://www.w3.org/2001/XMLSchema#" x

int main(int argc, char *argv[])
{
    using namespace Redland;

    int num = 1;

    if (argc > 1) {
        num = atoi(argv[1]);
    }

    World world;
    Namespaces namespaces;

    namespaces.add_prefix("rdf", RDF(""));
    namespaces.add_prefix("maths", MATHS(""));
    namespaces.add_prefix("spatial", SPATIAL(""));
    namespaces.add_prefix("tracking", TRACKING(""));
    namespaces.add_prefix("vom", VOM(""));
    namespaces.add_prefix("mea", MEA(""));
    namespaces.add_prefix("xsd", XSD(""));

    // storage=librdf_new_storage(world, "hashes", NULL,  "hash-type='memory'")
    // storage=librdf_new_storage(world, "hashes", "test", "hash-type='bdb',dir='.'")
    Storage storage(world, "hashes", 0, "hash-type='memory'");
    Model model(world, storage, 0);

    std::cout << "Producing " << num << " poses" << std::endl;

    for (int i = 0; i < num; ++i)
    {
        const std::string uuid_url = "http://test.arvida.de/UUID" + std::to_string(i);

        Arvida::RDF::Context ctx(world, namespaces, model, uuid_url);

        Node pose_node = Node::make_uri_node(world, uuid_url);

        Pose pose(
            Translation(1, 2, 3),
            Rotation(1, 1, 1, 1));

        Arvida::RDF::toRDF(ctx, pose_node, pose);
    }

    std::cout << "Writing poses to pose_redland.ttl" << std::endl;

    /* serialize */
    {
        librdf_serializer *ser = librdf_new_serializer(world.c_obj(), "turtle", NULL, NULL);

        namespaces.register_with_serializer(world, ser);

        if (!ser) {
            fprintf(stderr, "Could not load turtle serializer");
        }
        FILE *fd = fopen("pose_redland.ttl", "wb");

        librdf_serializer_serialize_model_to_file_handle(ser, fd, NULL, model.c_obj());

        fclose(fd);

        librdf_free_serializer(ser);
    }

    /* free everything */

#ifdef LIBRDF_MEMORY_DEBUG
    librdf_memory_report(stderr);
#endif

    /* keep gcc -Wall happy */
    return(0);
}
