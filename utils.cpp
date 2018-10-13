// Utilities file for PSO code
//
// 


#ifndef UTILS_CPP
#define UTILS_CPP
#include "Particle.hpp"
#include <vector>

enum Function {
    Rosenbrock,
    Ackley,
    Rastrigin
}

enum NeighborhoodTopology {
	Global,
	Ring,
	VonNeumann,
	Random
}

const double RosenbrockPosMin = 15.0;
const double RosenbrockPosMax = 30.0;
const double AckleyPosMin = 16.0;
const double AckleyPosMax = 32.0;
const double RastriginPosMin = 2.56;
const double RastriginPosMax = 5.12;
const double RosenbrockVelMin = -2;
const double RosenbrockVelMax = 2;
const double AckleyVelMin = -2;
const double AckleyVelMax = 4;
const double RastriginVelMin = -2;
const double RastriginVelMax = 4;


void getPosRangeForFunction(Function f, double &min, double &max){
	if (f == Function.Rosenbrock){
		min = RosenbrockPosMin;
		max = RosenbrockPosMax;
		return;
	}
	if (f == Function.Ackley){
		min = AckleyPosMin;
		max = AckleyPosMax;
		return;
	}
	if (f == Function.Rastrigin){
		min = RastriginPosMin;
		max = RastriginPosMax;
		return;
	}
}

void getVelRangeForFunction(Function f, double &min, double &max){
	if (f == Function.Rosenbrock){
		min = RosenbrockVelMin;
		max = RosenbrockVelMax;
		return;
	}
	if (f == Function.Ackley){
		min = AckleyVelMin;
		max = AckleyVelMax;
		return;
	}
	if (f == Function.Rastrigin){
		min = RastriginVelMin;
		max = RastriginVelMax;
		return;
	}
}

double randomDoubleInRange(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

void vonNeumann(vector<Particle> particles) {
	int rows;
	switch (particles.size()) {
		case 16 : rows = 4; break;
		case 30 : rows = 5; break;
		case 49 : rows = 7; break;
	}
	int columns = particles.size()/rows;
	int ** vn = vnArray(rows, columns);
	int rup, rdown, cr, cl;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < rows; j++) {
			rup = i + 1;
			rdown = i - 1;
			cl = j - 1;
			cr = j + 1;

			if (i = 0) {
				rup = rows - 1;
				rdown = i + 1;
			}
			if (i = (rows-1)) {
				rup = i - 1;
				rdown = 0;
			}
			if (j = 0){
				cl = columns - 1;
				cr = j + 1;
			}
			if (j == columns - 1) {
				cl = j - 1;
				cr = 0
			}

			particles[vn[i][j]].neighborhood.pushback(&particles[rup][j]); // up
			particles[vn[i][j]].neighborhood.pushback(&particles[rdown][j]); // down
			particles[vn[i][j]].neighborhood.pushback(&particles[i][cr]); // right
			particles[vn[i][j]].neighborhood.pushback(&particles[i][cl]); // left
		}
	}
}

int** vnArray(int rows, int columns) {
	int ** indecies = new int*[rows];
	int count = 0;
	for (int i = 0; i < rows; i++) {
		indecies[i] = new int[columns];
		for (int j = 0; j < columns; j++) {
			indecies[i][j] = count;
			count++;
		}
	}
}

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


// void vonNeumann(vector<Particle> particles) {
// 	for (int i = 0; i < particles.size(); i++) {
// 		if (i == 0){
// 			particles[i].neighborhood.pushback(&particles[particles.size()-2]);
// 			particles[i].neighborhood.pushback(&particles[particles.size()-1]);
// 			particles[i].neighborhood.pushback(&particles[i+1]);
// 			particles[i].neighborhood.pushback(&particles[i+2]);
// 		}
// 		if (i == 1){
// 			particles[i].neighborhood.pushback(&particles[particles.size()-1]);
// 			particles[i].neighborhood.pushback(&particles[i-1]);
// 			particles[i].neighborhood.pushback(&particles[i+1]);
// 			particles[i].neighborhood.pushback(&particles[i+2]);
// 		}
// 		else if (i == (particles.size() - 2)){
// 			particles[i].neighborhood.pushback(&particles[i-2]);
// 			particles[i].neighborhood.pushback(&particles[i-1]);
// 			particles[i].neighborhood.pushback(&particles[i+1]);
// 			particles[i].neighborhood.pushback(&particles[0]);			
// 		}		

// 		else if (i == (particles.size() - 1)){
// 			particles[i].neighborhood.pushback(&particles[i-2]);
// 			particles[i].neighborhood.pushback(&particles[i-1]);
// 			particles[i].neighborhood.pushback(&particles[0]);
// 			particles[i].neighborhood.pushback(&particles[1]);			
// 		}	

// 		else {
// 			particles[i].neighborhood.pushback(&particles[i-2]);
// 			particles[i].neighborhood.pushback(&particles[i-1]);
// 			particles[i].neighborhood.pushback(&particles[i+1]);
// 			particles[i].neighborhood.pushback(&particles[i+2]);
// 		}
// 	}
// }


#endif
