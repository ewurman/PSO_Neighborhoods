//
//  Particle.cpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include "Particle.hpp"


Particle::Particle(int dimensions){
    this.pbestVal = INT_MAX;
    this.pbestLoc = new double[dimensions];
    this.position = new double[dimensions];
    this.velocity = new double[dimensions];
    //TODO: random initialization of position and velocity.
    this.dimensions = dimensions;
    this.neighborhood = new vector<position>();
}
        

Particle::Particle(int dimensions, vector<Particle> neighborhood){
    this.pbestVal = INT_MAX;
    this.pbestLoc = new double[dimensions];
    this.position = new double[dimensions];
    this.velocity = new double[dimensions];
    this.dimensions = dimension;
    this.neighborhood = neighborhood;
}

double* Particle::getNBestLoc(){
    double* nbestLoc = this.pbestLoc;
    double nbestVal = this.pbestVal;
    for (int i = 0; i < this.neighborhood.size(); i++){
        double val = this.neighborhood[i].getPBestVal();
        if (val < nbestVal){
            nbestVal = val;
            nbestLoc = this.neighborhood[i].getPBestLoc();
        }
    }
    return nbestLoc;
}

void Particle::udpdatePosition(){
    for (int i = 0; i < this.dimensions; i++){
        this.position[i] = this.position[i] + this.velocity[i];
    }
}


void Particle::update_velocity(){
    double* newVelocity = new double[this.dimensions];
    double* nbestLoc = this.getNBestLoc();
    for (int i = 0; i < this.dimensions; i++){
        double random1 = randomDoubleInRange(0, this.towardPbest);
        double random2 = randomDoubleInRange(0, this.towardNbest);
        newVelocity[i] = this.constrictionFactor * (this.velocity[i] + random1*(this.pbestLoc[i] - this.position[i]) +
                                                    random2*(nbestLoc[i] - this.position[i]));
    }
    double* toDelete = this.velocity;
    this.velocity = newVelocity;
    delete(toDelete);
}





