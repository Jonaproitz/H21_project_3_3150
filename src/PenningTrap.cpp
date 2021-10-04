
#include "PenningTrap.hpp"

//Constructor
PenningTrap::PenningTrap(double B0_in, double V0_in, double d_in){
    double B0_ = B0_in;
    double V0_ = V0_in;
    double d_ = d_in;
}

void PenningTrap::add_particle(Particle particle_in){
    particles.push_back(particle_in);
}

arma::vec PenningTrap::external_E_field(arma::vec r){
    arma::vec E;
    double x = r[0], y = r[1], z = r[2];
    E = {-2*x, -2*y, 4*z};
    E = V0_/(2.*d_*d_) * E;
    return E;
}