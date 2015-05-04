/*
 * pose_sordmm_reader.cpp
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
#include <tuple>

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

    if (argc < 2) {
        std::cerr << "Error: Please specify input file" << std::endl;
        return 1;
    }

    const char *fileName = argv[1];

    World world;

    world.add_prefix("rdf", RDF(""));
    world.add_prefix("maths", MATHS(""));
    world.add_prefix("spatial", SPATIAL(""));
    world.add_prefix("tracking", TRACKING(""));
    world.add_prefix("vom", VOM(""));
    world.add_prefix("mea", MEA(""));
    world.add_prefix("xsd", XSD(""));

    Model model(world, "http://reader.arvida.de/");

    std::cout << "Loading " << fileName << " file" << std::endl;

    model.load_file(world.prefixes().c_obj(), SERD_TURTLE, fileName, "");

    int i = 0;

    while (true) {
        const std::string uuid_url = "http://test.arvida.de/UUID" + std::to_string(i);

        Arvida::RDF::Context ctx(model, uuid_url);

        URI pose_node(world, uuid_url);

        Arvida::RDF::Triple triple = Arvida::RDF::find_triple(model, pose_node, Curie(model.world(), "rdf:type"), Curie(model.world(), "spatial:SpatialRelationship"));

        // 1. Check $this
        if (!triple.is_valid() || !triple.subject.is_uri())
        {
            std::cerr<<"Check 1 failed"<<std::endl;
            break;
        }
        const Node _this = triple.subject;

        // 2. Check blank _b1
        triple = Arvida::RDF::find_triple(model, Node(), Curie(model.world(), "rdf:type"), Curie(model.world(), "maths:LeftHandedCartesianCoordinateSystem3D"));
        if (!triple.is_valid() || !triple.subject.is_blank())
        {
            std::cerr<<"Check 2 failed"<<std::endl;
            break;
        }
        const Node _b1 = triple.subject;

        // 3. Check blank _b1
        if (!Arvida::RDF::check_triple(model, _this, Curie(model.world(), "spatial:sourceCoordinateSystem"), _b1))
        {
            std::cerr<<"Check 3 failed"<<std::endl;
            break;
        }

        // 4. Check blank _b0
        triple = Arvida::RDF::find_triple(model, Node(), Curie(model.world(), "rdf:type"), Curie(model.world(), "maths:RightHandedCartesianCoordinateSystem2D"));
        if (!triple.is_valid() || !triple.subject.is_blank())
        {
            std::cerr<<"Check 4 failed"<<std::endl;
            break;
        }
        Node _b0 = triple.subject;

        // 5. Check blank _b0
        if (!Arvida::RDF::check_triple(model, _this, Curie(model.world(), "spatial:targetCoordinateSystem"), _b0))
        {
            std::cerr<<"Check 5 failed"<<std::endl;
            break;
        }

        // 6. Check $that
        {
            const std::string path_14 = ctx.path + "/transl";
            Arvida::RDF::Context ctx_14(ctx, path_14);
            Sord::URI node_14(ctx.model.world(), path_14);

            triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:translation"), node_14);
            if (!triple.is_valid())
            {
                std::cerr<<"Check 6 failed"<<std::endl;
                break;
            }
            std::cerr << path_14 << ": " << triple.object.to_string() << std::endl;

            //ctx.model.add_statement(_this, Curie(ctx.model.world(), "spatial:translation"), Arvida::RDF::toRDF(ctx_14, node_14, value.getTranslation()));
        }

        // 7. Check $that
        {
            const std::string path_17 = ctx.path + "/rot";
            Arvida::RDF::Context ctx_17(ctx, path_17);
            Sord::URI node_17(ctx.model.world(), path_17);

            triple = Arvida::RDF::find_triple(ctx.model, _this, Curie(ctx.model.world(), "spatial:rotation"), node_17);
            if (!triple.is_valid())
            {
                std::cerr << "Check 7 failed" << std::endl;
                break;
            }
            std::cerr << path_17 << ": " << triple.object.to_string()<<std::endl;
        }

        std::cout<<"_this: " << _this.to_string() << std::endl;
        std::cout<<"_b0: " << _b0.to_string() << std::endl;
        std::cout<<"_b1: " << _b1.to_string() << std::endl;

        /*
        do {
            std::cout << "Subject: " << iter.get_subject().to_string() << std::endl;
            std::cout << "Predicate: " << iter.get_predicate().to_string() << std::endl;
            std::cout << "Object: " << iter.get_object().to_string() << std::endl;
        } while (!iter.next());
        */
        ++i;
    }

#if 0
    for (int i = 0; i < num; ++i)
    {
        const std::string uuid_url = "http://test.arvida.de/UUID" + std::to_string(i);

        Arvida::RDF::Context ctx(model, uuid_url);

        URI pose_node(world, uuid_url);

        Pose pose(
            Translation(1, 2, 3),
            Rotation(1, 1, 1, 1));

        Arvida::RDF::toRDF(ctx, pose_node, pose);
    }

    std::cout << "Writing poses" << std::endl;
#endif

    model.write_to_file("pose_sordmm_reader.ttl", SERD_TURTLE,
        (SerdStyle)(SERD_STYLE_ABBREVIATED | SERD_STYLE_CURIED | SERD_STYLE_RESOLVED));

    model.write_to_file("pose_sordmm_reader.nt", SERD_NTRIPLES,
        (SerdStyle)(SERD_STYLE_ABBREVIATED | SERD_STYLE_CURIED | SERD_STYLE_RESOLVED));

    return 0;
}
