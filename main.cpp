
#include "PenningTrap.hpp"
#include <iomanip>

int main(){
    // Initialize Penning trap.
    double B0 = 9.65e1, V0 = 9.65e8, d = 1e4;
    PenningTrap my_trap(B0, V0, d);

    // Add particles
    arma::vec pos_1 = {5, 0, 0}, vel_1 = {0, 2, -5};
    Particle particle_1(1, 1, pos_1, vel_1);
    my_trap.add_particle(particle_1);

    arma::vec pos_2 = {1, 3, 0}, vel_2 = {1, -2, 2};
    Particle particle_2(1, 1, pos_2, vel_2);
    my_trap.add_particle(particle_2);

    int n = my_trap.particles.size();

    int T = 100;
    double dt = 1e-3;
    int N = T / dt + 1;
    arma::vec t = arma::linspace(0, T, N);


    // Open files
    std::string filename_1 = "positions.txt";
    std::string filename_2 = "velocities.txt";
    std::ofstream ofile_1;
    ofile_1.open(filename_1);
    std::ofstream ofile_2;
    ofile_2.open(filename_2);

    // Set width and precision
    int width = 18;
    int prec = 10;

    // Complete calculation and write to file
    for (int t_i = 1; t_i < N; t_i++){
        my_trap.evolve_RK4(dt);
        for (int i = 0; i < n; i++){
            ofile_1 << i
                    << std::setw(width) << std::setprecision(prec) << std::scientific << my_trap.particles[i].position(0)
                    << std::setw(width) << std::setprecision(prec) << std::scientific << my_trap.particles[i].position(1)
                    << std::setw(width) << std::setprecision(prec) << std::scientific << my_trap.particles[i].position(2)
                    << std::endl;
            ofile_2 << i
                    << std::setw(width) << std::setprecision(prec) << std::scientific << my_trap.particles[i].velocity(0)
                    << std::setw(width) << std::setprecision(prec) << std::scientific << my_trap.particles[i].velocity(1)
                    << std::setw(width) << std::setprecision(prec) << std::scientific << my_trap.particles[i].velocity(2)
                    << std::endl;
        }
    }

    // Close output file
    ofile_1.close();
    ofile_2.close();

    return 0;
}