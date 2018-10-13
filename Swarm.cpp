//
//  Swarm.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include "Swarm.hpp"
#include "Particle.cpp"
#include <vector>

/*
class Swarm {

    private:
        int numIterations;
        int swarmSize;
        int dimensions;
        vector<Particle> particles;
        Function function;
        NeighborhoodTopology topology;

    public:
        Swarm(int iterations, int numParticles, int dimensions, Function f, NeighborhoodTopology topology);

        void PSO();

        
};
*/

Swarm::Swarm(int iterations, int numParticles, int dimensions, Function f, NeighborhoodTopology topology){
    this.numIterations = iterations;
    this.swarmSize = numParticles;
    this.dimensions = dimensions;
    this.function = f;
    this.topology = topology;
    double minPos, maxPos, minVel, maxVel;
    getPosRangeForFunction(f, minPos, maxPos);
    getPosRangeForFunction(f, minVel, maxVel);
    for (int i = 0; i < numParticles; i++){
        Particle p = new Particle(dimensions, minPos, maxPos, minVel, maxVel);
        this.particles.push_back(p);
    }

}
