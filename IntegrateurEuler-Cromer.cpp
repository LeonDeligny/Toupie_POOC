#include "IntegrateurEuler-Cromer.h"
#include <iostream>
using namespace std;

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const double& dt) {
    spin.set_vitesses(spin.get_vitesses_() + dt * spin.f(spin.get_position(), spin.get_vitesses_()));
    spin.set_position(spin.get_position() + dt * spin.get_vitesses_());

    cout << "parametres : " << spin.get_position();
    cout << " ; derivee : " << spin.get_vitesses_() << endl;
}