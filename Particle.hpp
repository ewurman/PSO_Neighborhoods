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


class Particle {
    static constexpr double constrictionFactor = 0.7298;
    static constexpr double towardPbest = 2.05;
    static constexpr double towardNbest = 2.05;

    private:
        double pbestVal;
        double* pbestLoc; // these are arrays of x_i values representing position or velocity in d dimensions
        double* position;
        double* velocity;
        int dimensions;
        std::vector <Particle*> neighborhood; // We don;t include this particle in the neighbors
    
    
    public:
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
