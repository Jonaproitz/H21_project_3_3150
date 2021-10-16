
#include "PenningTrap.hpp"

int main(){
    // Initialize Penning trap.
    double B0 = 9.65e1, V0 = 9.65e8, d = 1e4;
    PenningTrap my_trap(B0, V0, d);

    // Add particle
    arma::vec pos = {1, 1, 1}, vel = {-1, -1, -1};
    Particle particle_1(1, 1, pos, vel);
    my_trap.add_particle(particle_1);

    my_trap.evolve_RK4(1e-4);
    my_trap.particles[0].velocity.print();

    my_trap.particles[0].velocity = vel;
    my_trap.particles[0].position = pos;
    my_trap.evolve_forward_Euler(1e-4);
    my_trap.particles[0].velocity.print();

    return 0;
}