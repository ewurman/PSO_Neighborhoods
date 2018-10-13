//
//  Swarm.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include "Swarm.hpp"
#include "Particle.cpp"
#include <vector>


Swarm::Swarm(int iterations, int numParticles, int dimensions, Function f, NeighborhoodTopology topology){
    this->numIterations = iterations;
    this->swarmSize = numParticles;
    this->dimensions = dimensions;
    this->function = f;
    this->topology = topology;
    double minPos, maxPos, minVel, maxVel;
    getPosRangeForFunction(f, minPos, maxPos);
    getPosRangeForFunction(f, minVel, maxVel);
    for (int i = 0; i < numParticles; i++){
        Particle p = new Particle(dimensions, minPos, maxPos, minVel, maxVel);
        this->particles.push_back(p);
    }
    initializeNeighborhoods();
}

void Swarm::initializeNeighborhoods(){
    if (this->topology == NeighborhoodTopology.Global){
        global(this->particles);
    }
    if (this->topology == NeighborhoodTopology.Ring){
        ring(this->particles);
    }
    if (this->topology == NeighborhoodTopology.VonNeumann){
        vonNeumann(this->particles);
    }
    if (this->topology == NeighborhoodTopology.Random){
        randNeighbors(this->particles, randomNeighborNum);
    }
}

void Swarm::evaluate() {
	for (int i = 0; i < this.numParticles; i++) {
        this.particles 
	}
}

void Swarm::pso(){
	Swarm.evaluate();

	for (int i = 0; i < iterations; i++) {
		for (int j = 0; j < this.numParticles; j++) {
			
		}
	}
}
