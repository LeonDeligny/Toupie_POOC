#include "IntegrateurEulerCromer.hpp"
#include <iostream>
using namespace std;

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const double& dt) {
    spin.set_derivees(spin.get_derivees_() + dt * spin.f());
    
    spin.set_parametres(spin.get_parametres() + dt * spin.get_derivees_());

   cout << "parametres : " << spin.get_parametres();
    cout << " ; derivee : " << spin.get_derivees_() << endl;
}
