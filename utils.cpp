// Utilities file for PSO code
//
// 


#ifndef UTILS_CPP
#define UTILS_CPP

double randomDoubleInRange(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


#endif