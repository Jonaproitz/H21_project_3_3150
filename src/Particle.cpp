
#include "Particle.hpp"

// Constructor
Particle::Particle(int charge_in, double mass_in, arma::vec position_in, arma::vec velocity_in){
    charge_ = charge_in;
    mass_ = mass_in;
    position_ = position_in;
    velocity_ = velocity_in;
}

int Particle::charge(){
    return charge_;
}

double Particle::mass(){
    return mass_;
}

arma::vec Particle::position(){
    return position_;
}

arma::vec Particle::velocity(){
    return velocity_;
}