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
        Particle p = *new Particle(dimensions, minPos, maxPos, minVel, maxVel);
        this->particles.push_back(p);
    }
    initializeNeighborhoods();
}

void Swarm::initializeNeighborhoods(){
    if (this->topology == Global){
        global(this->particles);
    }
    if (this->topology == Ring){
        ring(this->particles);
    }
    if (this->topology == VonNeumann){
        vonNeumann(this->particles);
    }
    if (this->topology == Random){
        randNeighbors(this->particles, randomNeighborNum);
    }
}


void Swarm::evaluate() {
	for (int i = 0; i < this->swarmSize; i++) {
        double eval;
        switch (this->function) {
            case Rosenbrock:
                eval = evaluateRosenbrock(this->particles[i]., <#int dimensions#>);
                break;
            case Ackley:
                eval = evaluateAckley(<#double *pos#>, <#int dimensions#>);
                break;
            case Rastrigin:
                eval = evaluateRastrigin(<#double *pos#>, <#int dimensions#>);
            default:
                break;
        }
        if (eval < this->particles[i].getPBestLoc()) {
            this->particles[i].pbestLoc = eval;
        }
	}
    
}

void Swarm::pso(){
	//Swarm.evaluate();

	for (int i = 0; i < this->numIterations; i++) {
		for (int j = 0; j < this->swarmSize; j++) {
			
		}
	}
}
