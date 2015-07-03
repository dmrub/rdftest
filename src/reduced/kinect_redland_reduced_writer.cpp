/*
 * kinect_redland_writer.cpp
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

#define REDLAND_LIB
#include "redland.hpp"
#include "GenRedlandReducedKinectTraits.hpp"
#include "ReducedKinectTraits.hpp"


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
    namespaces.add_prefix("skel", SKEL(""));
    namespaces.add_prefix("service", SERVICE(""));
    namespaces.add_prefix("core", CORE(""));

    Storage storage(world, "hashes", 0, "hash-type='memory'");
    Model model(world, storage, 0);

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

    std::vector< std::shared_ptr<Quantity> > quantities;
    quantities.push_back(leftElbowRotation);
    quantities.push_back(leftLowerArmTranslation);
    quantities.push_back(leftUpperArmTranslation);

    SkeletonTrackingService sts;
    sts.getQuantityManager().setQuantities(std::move(quantities));

    PathManager pm("file:///example.com/kinect");

    {
        Arvida::RDF::Context ctx(world, namespaces, model, pm.base_path, &pm);
        Node sts_node(world, pm.base_path);

        Arvida::RDF::toRDF(ctx, sts_node, sts);
    }

    std::cout << "Writing RDF to kinect_redland_reduced.ttl" << std::endl;

    /* serialize */
    {
        librdf_serializer *ser = librdf_new_serializer(world.c_obj(), "turtle", NULL, NULL);

        namespaces.register_with_serializer(world, ser);

        if (!ser) {
            fprintf(stderr, "Could not load turtle serializer");
        }
        FILE *fd = fopen("kinect_redland_reduced.ttl", "wb");

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
