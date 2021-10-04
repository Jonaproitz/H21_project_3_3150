
#include "PenningTrap.hpp"

int main(){
    // Initialize Penning trap.
    double B0 = 9.65e1, V0 = 9.65e8, d = 1e4;
    PenningTrap my_trap(B0, V0, d);

    // Add particle
    arma::vec pos = {1, 1, 1}, vel = {-1, -1, -1};
    Particle particle_1(1, 1, pos, vel);
    my_trap.add_particle(particle_1);
    std::cout << my_trap.particles[0].velocity() << std::endl;

    my_trap.evolve_forward_Euler(1e-2);
    std::cout << my_trap.particles[0].velocity() << std::endl;

    return 0;
}