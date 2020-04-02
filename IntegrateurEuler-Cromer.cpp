#include "IntegrateurEuler-Cromer.h"
#include <iostream>
using namespace std;

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const double& dt) {
    spin.set_vitesses(spin.get_vitesses_() + dt * spin.f(spin.get_angle(), spin.get_vitesses_()));
    spin.set_angle(spin.get_angle() + dt * spin.get_vitesses_());

    cout << "parametres : " << spin.get_angle();
    cout << " ; derivee : " << spin.get_vitesses_() << endl;
}