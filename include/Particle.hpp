
#include <armadillo>

#ifndef __Particle_hpp__
#define __Partilce_hpp__

class Particle{
private:
  // Declaration of variables only accessible from within the class

public:
  // Declaration of constructor
    Particle(int charge, double mass, arma::vec position, arma::vec velocity);

};

#endif