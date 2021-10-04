
#include "PenningTrap.hpp"

//Constructor
PenningTrap::PenningTrap(double B0_in, double V0_in, double d_in){
    B0_ = B0_in;
    V0_ = V0_in;
    d_ = d_in;
}

void PenningTrap::add_particle(Particle particle_in){
    particles.push_back(particle_in);
}

arma::vec PenningTrap::external_E_field(arma::vec r){
    arma::vec E;
    double x = r[0], y = r[1], z = r[2];
    E = {-2*x, -2*y, 4*z};
    E = -V0_/(2.*d_*d_) * E;
    return E;
}

arma::vec PenningTrap::external_B_field(arma::vec r){
    arma::vec B;
    B = {0, 0, B0_};
    return B;
}

arma::vec PenningTrap::force_particle(int i, int j){
    double k_e = 1.38935333e5;
    arma::vec f, pos_i = particles[i].position, pos_j = particles[j].position;
    f = k_e * particles[i].charge * particles[j].charge * (
        pos_i - pos_j) / pow(arma::norm(pos_i - pos_j), 3.);
    return f;
}

arma::vec PenningTrap::total_force_external(int i){
    arma::vec F_ext;
    F_ext = particles[i].charge * (external_E_field(particles[i].position) + arma::cross(particles[i].velocity, external_B_field(particles[i].position)));
    return F_ext;
}

arma::vec PenningTrap::total_force_particles(int i){
    arma::vec f_tot = arma::vec(3).fill(0.);
    for (int j = 0; j < particles.size(); j++){
        if (j != i){
            f_tot = f_tot + force_particle(i, j);
        }
    }
    return f_tot;
}

arma::vec PenningTrap::total_force(int i){
    arma::vec F;
    F = total_force_external(i) + total_force_particles(i);
    return F;
}

void PenningTrap::evolve_RK4(double dt){
    arma::vec k1, k2, k3, k4;
    arma::mat v = arma::mat(3, particles.size());
    for (int i = 0; i < particles.size(); i++){
        k1 = 1/particles[i].mass * total_force(i);
        
    }
}

void PenningTrap::evolve_forward_Euler(double dt){
    arma::mat V = arma::mat(particles.size(), 3);
    for (int i = 0; i < particles.size(); i++){
        V.row(i) = particles[i].velocity + total_force(i) / particles[i].mass * dt;
    }
}