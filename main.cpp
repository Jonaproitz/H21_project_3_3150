
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
    arma::cube v = arma::cube(3, N, n), r = arma::cube(3, N, n);


    for (int j = 0; j < n; j++){
        v.slice(j).col(0) = my_trap.particles[j].velocity;
        r.slice(j).col(0) = my_trap.particles[j].position;
    }


    for (int t_i = 1; t_i < N; t_i++){
        my_trap.evolve_RK4(dt);
        for (int i = 0; i < n; i++){
            v.slice(i).col(t_i) = my_trap.particles[i].velocity;
            r.slice(i).col(t_i) = my_trap.particles[i].position;
        }
    }

    // Write positions to file
    std::string filename = "positions.txt";
    std::ofstream ofile;
    ofile.open(filename);

    // Set width and precision
    int width = 18;
    int prec = 10;

    for (int t_i = 0; t_i < N; t_i++){
        for (int i = 0; i < n; i++){
            ofile << i
                  << std::setw(width) << std::setprecision(prec) << std::scientific << r.slice(i).col(t_i)(0)
                  << std::setw(width) << std::setprecision(prec) << std::scientific << r.slice(i).col(t_i)(1)
                  << std::setw(width) << std::setprecision(prec) << std::scientific << r.slice(i).col(t_i)(2)
                  << std::endl;
        }
    }

    // Close output file
    ofile.close();

    return 0;
}