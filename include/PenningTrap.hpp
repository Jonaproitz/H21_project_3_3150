
#include "Particle.hpp"
#include <vector>

class PenningTrap{
    private:

    public:
        PenningTrap(double B0_in, double V0_in, double d_in);

        void add_particle(Particle particles_in);
};