//
//  main.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include <iostream>

#include "Particle.cpp"
#include "Swarm.cpp"

using namespace std;

enum Function {
    rosenbrock,
    ackley,
    rastrigin
}

enum Topology {
	global,
	ring,
	von_Neumann,
	random
}

int main(int argc, const char * argv[]) {

	char * topology = argv[1];
	char * num_particles = atof(argv[2]);
	int iterations = atof(argv[3]);
	char * func = argv[4];
	int * dimensions = atof(argv[5]);


	// initialize particles

	// establish neighborhoods
    if (!strcmp(argv[1], "gl")) {
    } else if (!strcmp(topology, "ri")) {
    } else if (!strcmp(topology, "vn")) {
    } else if (!strcmp(topology, "ra")) {
    } else {
        cout << "Enter valid Topology method ( gl, ri, vn, ra )" << endl;
        return null;
    }

    // run interations
    for (int i = 0; i < interations; i++) {
    	
    }

    // find best so far


    return 0;
}
