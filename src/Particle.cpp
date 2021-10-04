
#include "Particle.hpp"

// Constructor
Particle::Particle(int charge_in, double mass_in, arma::vec position_in, arma::vec velocity_in){
    charge = charge_in;
    mass = mass_in;
    position = position_in;
    velocity = velocity_in;
}

}