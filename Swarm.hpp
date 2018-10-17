//
//  Swarm.hpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//
#include <stdio.h>
#include <vector>
#include "utils.cpp"


#ifndef Swarm_hpp
#define Swarm_hpp



class Swarm {

    const static int randomNeighborNum = 5;

    private:
        int numIterations;
        int swarmSize;
        int dimensions;
        Function function;
        NeighborhoodTopology topology;
        vector<Particle> particles;
        double globalBestVal;
        double* globalBestLoc;

    public:
        Swarm(int iterations, int numParticles, int dimensions, Function f, NeighborhoodTopology topology);
        void initializeNeighborhoods();
        void updateThenEvaluate();
        void evaluate();
        void update_swarm_pos();
        void pso();
        
};



#endif /* Swarm_hpp */
