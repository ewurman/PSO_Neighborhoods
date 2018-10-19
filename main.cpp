//
//  main.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//
#include <fstream>
#include <iostream>
#include "Swarm.cpp"


using namespace std;

int main(int argc, const char * argv[]) {

    bool scriptingAll = false;
    if (argc == 1){
        scriptingAll = true;
    }
    else if (argc != 6){
        cout << "Must have 5 additional arguments: <topology> <swarm_size> <iterations> <function> <dimensions>" << endl;
        cout << "you had " << argc - 1 << " additional arguments" << endl;
        exit(1);
    }
    else {
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

        srand(time(0));
        Swarm* swarm = new Swarm(iterations, num_particles, dimensions, function, topology);
        swarm->pso();

    }
    
    if (scriptingAll){
        srand(time(0));

        //string filename = "Summary.csv";
        //fstream summaryfile;
        //summaryfile.open(filename);
        int swarm_sizes[] = {16, 30, 49};
        string functionNames[] = {"Rosenbrock", "Ackley", "Rastrigin"};
        string topologyNames[] = {"Global", "Ring", "VonNeumann", "Random"};
        int iterations = 1000;
        int dimensions = 30;
        for (int i = 0; i < 3; i++) { // For each function 
            Function f = static_cast<Function>(i);
            string functionFilename = functionNames[i] + ".csv";
            fstream functionFile;
            functionFile.open(functionFilename, ios::out);
            functionFile << "Number Of Particles,Best Value" << endl;
            cout << "opened file " << functionFilename << endl;
            for (int j = 0; j < 4; j++) { //For each topology
                NeighborhoodTopology top = static_cast<NeighborhoodTopology>(j);
                string topName = topologyNames[j];
                for (int k = 0; k < 3; k++){
                    int num_particles = swarm_sizes[k];
                    for (int trial = 0; trial < 20; trial++){
                        Swarm* swarm = new Swarm(iterations, num_particles, dimensions, f, top);
                        double value = swarm->pso2();
                        //summaryfile << 
                        functionFile << num_particles << "," << value << endl;
                        delete(swarm);
                    }
                }
                functionFile << "#" << topName << endl;
            }
            functionFile.close();
            cout << "closed file " << functionFilename << endl;
        }

        //summaryfile.close();

    }

    return 0;
}
