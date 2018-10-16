//
//  main.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include <iostream>
#include "Swarm.cpp"
#include "koolplot.h"


using namespace std;
//int main() {
//    plotdata x(0, 10);
//    plotdata y = sin(x) + x/5;
//    plot(x, y);
//    return 0;
//}
int main(int argc, const char * argv[]) {

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


    // Below this point can be done in Swarm::pso();



    return 0;
}
