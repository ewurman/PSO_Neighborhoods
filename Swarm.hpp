//
//  Swarm.hpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

//
//  Particle.hpp
//  Proj2
//
//  Created by Ian Squiers and Erik Wurman on 10/12/18.
//

#ifndef Swarm_hpp
#define Swarm_hpp

#include <stdio.h>
#include <vector>
#include "utils.cpp"


class Swarm {
    static double constrictionFactor = 0.7298;
    static double towardPbest = 2.05;
    static double towardNbest = 2.05;

    private:
        
        
        
    public:
        Particle(int dimensions);
        Particle(int dimensions, vector<Particle> neighborhood);

        double getPBestVal() { return this.pbestVal; }
        double* getPBestLoc() { return this.pbestLoc; }
        double* getPosition() { return this.position; }
        double* getVelocity() { return this.velocity; }


        double* getNBestLoc();
        void update_position();
        void update_velocity(); //maybe parameters like inertia rate, etc or make them constants
};



#endif /* Particle_hpp */