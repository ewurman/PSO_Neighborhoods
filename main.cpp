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

int main(int argc, const char * argv[]) {

	char * topologytype = argv[1];
	int num_particles = atoi(argv[2]);
	int iterations = atoi(argv[3]);
	char * func = argv[4];
	int dimensions = atoi(argv[5]);

	// establish which neighborhood
    NeighborhoodTopology topology;
    if (!strcmp(topologytype, "gl")) {
        topology = NeighborhoodTopology.Global;
    } 
    else if (!strcmp(topologytype, "ri")) {
        topology = NeighborhoodTopology.Ring;
    } 
    else if (!strcmp(topologytype, "vn")) {
        topology = NeighborhoodTopology.VonNeumann;
    } 
    else if (!strcmp(topologytype, "ra")) {
        topology = NeighborhoodTopology.Random;
    } 
    else {
        cout << "Enter valid Topology method ( gl, ri, vn, ra )" << endl;
        return 1;
    }

    // establish which function
    Function function;
    if (!strcmp(func, "rok")) {
        function = Function.Rosenbrock;
    } 
    else if (!strcmp(func, "ack")) {
        function = Function.Ackley;
    } 
    else if (!strcmp(func, "ras")) {
        function = Function.Rastrigin;
    } 
    else {
        cout << "Enter valid Function for PSO (rok, ack, ras)" << endl;
        return 1;
    }


    // Below this point can be done in Swarm::pso();



    return 0;
}
