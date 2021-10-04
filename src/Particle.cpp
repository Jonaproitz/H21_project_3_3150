
#include "Particle.hpp"

// Constructor
Particle::Particle(int charge_in, double mass_in, arma::vec position_in, arma::vec velocity_in){
    int charge_ = charge_in;
    double mass_ = mass_in;
    arma::vec position_ = position_in;
    arma::vec velocity_ = velocity_in;
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