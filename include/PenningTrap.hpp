
#include "Particle.hpp"
#include <vector>

class PenningTrap{
    private:

    public:
        PenningTrap(double B0_in, double V0_in, double d_in);

        // Add a particle to the trap
        void add_particle(Particle particles_in);

        // External electric field at point r=(x,y,z)
        arma::vec external_E_field(arma::vec r);
        
        // External magnetic field at point r=(x,y,z)
        arma::vec external_B_field(arma::vec r);
};