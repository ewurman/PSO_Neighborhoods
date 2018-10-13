// Utilities file for PSO code
//
// 


#ifndef UTILS_CPP
#define UTILS_CPP
#include "Particle.hpp"
#include <vector>

double randomDoubleInRange(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

//ARE you included in your own neighborhood?

void ring(vector<Particle> particles) {
	for (int i = 0; i < particles.size(); i++) {
		if (i == 0){
			particles[i].neighborhood.pushback(&particles[particles.size()-1]);
			particles[i].neighborhood.pushback(&particles[i+1]);
		}
		else if (i == (particles.size() - 1)){
			particles[i].neighborhood.pushback(&particles[i-1]);
			particles[i].neighborhood.pushback(&particles[i+1]);
		}
		else {
			particles[i].neighborhood.pushback(&particles[i+1]);
			particles[i].neighborhood.pushback(&particles[i-1]);
		}
	}
}

void vonNeumann(vector<Particle> particles) {
	for (int i = 0; i < particles.size(); i++) {
		if (i == 0){
			particles[i].neighborhood.pushback(&particles[particles.size()-2]);
			particles[i].neighborhood.pushback(&particles[particles.size()-1]);
			particles[i].neighborhood.pushback(&particles[i+1]);
			particles[i].neighborhood.pushback(&particles[i+2]);
		}
		if (i == 1){
			particles[i].neighborhood.pushback(&particles[particles.size()-1]);
			particles[i].neighborhood.pushback(&particles[i-1]);
			particles[i].neighborhood.pushback(&particles[i+1]);
			particles[i].neighborhood.pushback(&particles[i+2]);
		}
		else if (i == (particles.size() - 2)){
			particles[i].neighborhood.pushback(&particles[i-2]);
			particles[i].neighborhood.pushback(&particles[i-1]);
			particles[i].neighborhood.pushback(&particles[i+1]);
			particles[i].neighborhood.pushback(&particles[0]);			
		}		

		else if (i == (particles.size() - 1)){
			particles[i].neighborhood.pushback(&particles[i-2]);
			particles[i].neighborhood.pushback(&particles[i-1]);
			particles[i].neighborhood.pushback(&particles[0]);
			particles[i].neighborhood.pushback(&particles[1]);			
		}	

		else {
			particles[i].neighborhood.pushback(&particles[i-2]);
			particles[i].neighborhood.pushback(&particles[i-1]);
			particles[i].neighborhood.pushback(&particles[i+1]);
			particles[i].neighborhood.pushback(&particles[i+2]);
		}
	}
}

void global(vector<Particle> particles) {
	for (int i = 0; i < particles.size(); i++) {
		for (int j = 0; j < particles.size(); j++) {
			if (i != j) {
				particles[i].neighborhood.pushback(&particles[j])
			}
		}
	}
}

void randNeighbors(vector<Particle> particles, int numNeighbors) {
	vector<int> used;
	std::vector<int>::iterator it;
	for (int i = 0; i < particles.size(); i++) {
		for (int j = 0; j < numNeighbors; j++) {
			int r = rand() % particles.size();

			it = find(used.begin(), used.end(), r);


			while (it != used.end()) {
				int r = rand() % particles.size();
				it = find(used.begin(), used.end(), r);
			}

			particles[i].neighborhood.pushback(&particles[r]);
			used.pushback(r);
		}
	}
}


#endif