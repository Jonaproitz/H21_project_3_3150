
#include <armadillo>

#ifndef __Particle_hpp__
#define __Partilce_hpp__

class Particle{
public:
    // Declaration of public variables
    int charge;
    double mass;
    arma::vec position;
    arma::vec velocity;

    // Declaration of constructor
    Particle(int charge, double mass, arma::vec position, arma::vec velocity);
};

#endif