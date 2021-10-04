
#include "PenningTrap.hpp"

int main(){
    // Initialize Penning trap.
    double B0 = 9.65e1, V0 = 9.65e8, d = 1e4;
    PenningTrap my_trap(B0, V0, d);

    // Add particle
    arma::vec pos = {1, 1, 1}, vel = {-1, -1, -1};
    Particle particle1(1, 1, pos, vel);
    std::cout << particle1.position() << std::endl;

    return 0;
}