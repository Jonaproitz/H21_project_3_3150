
#include "PenningTrap.hpp"

int main(){
    // Initialize Penning trap.
    double B0 = 9.65e1, V0 = 9.65e8, d = 1e4;
    PenningTrap my_trap(B0, V0, d);

    // Add particle
    arma::vec pos = {1, 1, 1}, vel = {-1, -1, -1};
    Particle particle_1(1, 1, pos, vel);
    my_trap.add_particle(particle_1);

    int n = my_trap.particles.size();

    int T = 10;
    double dt = 1e-4;
    int N = T / dt + 1;
    arma::cube v = arma::cube(3, N, n), r = arma::cube(3, N, n);
    for (int j = 0; j < n; j++){
        v.slice(j).col(0) = my_trap.particles[j].velocity;
    }
    for (int t_i = 1; t_i < N; t_i++){
        my_trap.evolve_RK4(dt);
        for (int i = 0; i < n; i++){
            v.slice(i).col(t_i) = my_trap.particles[i].velocity;
            r.slice(i).col(t_i) = my_trap.particles[i].position;
        }
    }

    return 0;
}