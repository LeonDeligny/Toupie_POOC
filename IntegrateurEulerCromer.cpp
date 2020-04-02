#include "IntegrateurEulerCromer.hpp"
#include <iostream>
using namespace std;

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const double& dt) {
    cout << spin.get_derivees_() + dt * spin.f();
    spin.set_derivees(spin.get_derivees_() + dt * spin.f());
    
    cout << spin.get_parametres() + dt * spin.get_derivees_();
    spin.set_parametres(spin.get_parametres() + dt * spin.get_derivees_());

   cout << "parametres : " << spin.get_parametres();
    cout << " ; derivee : " << spin.get_derivees_() << endl;
}
