//
//  main.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include <iostream>
#include "Swarm.cpp"

using namespace std;

int main(int argc, const char * argv[]) {

    if (argc != 6){
        cout << "Must have 5 additional arguments: <topology> <swarm_size> <iterations> <function> <dimensions>" << endl;
        cout << "you had " << argc - 1 << " additional arguments" << endl;
        exit(1);
    }


    const char * topologytype = argv[1];
    int num_particles = atoi(argv[2]);
    int iterations = atoi(argv[3]);
    const char * func = argv[4];
    const int dimensions = atoi(argv[5]);

    // establish which neighborhood
    NeighborhoodTopology topology;
    if (!strcmp(topologytype, "gl")) {
        topology = Global;
    }
    else if (!strcmp(topologytype, "ri")) {
        topology = Ring;
    }
    else if (!strcmp(topologytype, "vn")) {
        topology = VonNeumann;
    }
    else if (!strcmp(topologytype, "ra")) {
        topology = Random;
    }
    else {
        cout << "Enter valid Topology method ( gl, ri, vn, ra )" << endl;
        return 1;
    }

    // establish which function
    Function function;
    if (!strcmp(func, "rok")) {
        function = Rosenbrock;
    }
    else if (!strcmp(func, "ack")) {
        function = Ackley;
    }
    else if (!strcmp(func, "ras")) {
        function = Rastrigin;
    }
    else {
        cout << "Enter valid Function for PSO (rok, ack, ras)" << endl;
        return 1;
    }

    //seed random to get more random value
    srand(time(0));
    
    // Below this point can be done in Swarm::pso();
    Swarm* swarm = new Swarm(iterations, num_particles, dimensions, function, topology);
    swarm->pso();


    return 0;
}
