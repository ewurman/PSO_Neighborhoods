//
//  Particle.hpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#include <stdio.h>
#include <vector>
#include "utils.cpp"

#ifndef Particle_hpp
#define Particle_hpp


double CONSTRICTION_FACTOR = 0.7298;
double TOWARD_PBEST = 2.05;
double TOWARD_NBEST = 2.05;


class Particle {

    private:
        double pbestVal;
        double* pbestLoc; // these are arrays of x_i values representing position or velocity in d dimensions
        double* position;
        double* velocity;
        int dimensions;
    
    public:
        std::vector <Particle*> neighborhood; // We don;t include this particle in the neighbors

        Particle(int dimensions, double startPosMin, double startPosMax, double startVelMin, double startVelMax);
        Particle(int dimensions, double startPosMin, double startPosMax, double startVelMin, double startVelMax, std::vector<Particle*> neighborhood);

        double getPBestVal() { return this->pbestVal; }
        double* getPBestLoc() { return this->pbestLoc; }
        double* getPosition() { return this->position; }
        double* getVelocity() { return this->velocity; }


        double* getNBestLoc();
        void update_position();
        void update_velocity(); //maybe parameters like inertia rate, etc or make them constants
};



#endif /* Particle_hpp */
