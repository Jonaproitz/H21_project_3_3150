
#include <armadillo>

#ifndef __Particle_hpp__
#define __Partilce_hpp__

class Particle{
private:
    // Declaration of variables only accessible from within the class
    int charge_;
    double mass_;
    arma::vec position_;
    arma::vec velocity_;

public:
    // Declaration of constructor
    Particle(int charge, double mass, arma::vec position, arma::vec velocity);

    // Method that returns the charge of a particle
    int charge();

    // Method that returns the mass of a particle
    double mass();

    // Method that returns positoon of particle
    arma::vec position();

    // Method that returns velocity of particle
    arma::vec velocity();
};

#endif