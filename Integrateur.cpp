#include "Integrateur.hpp"
#include "Toupie.hpp"
using namespace std;
void Integrateur::evolue(Toupie& spin, const double& dt) {
    cout << spin.get_parametres() + dt * spin.get_derivees_();
    spin.set_parametres(spin.get_parametres() + dt * spin.get_derivees_());
    
    cout << spin.get_derivees_() + dt * spin.f();
    spin.set_derivees(spin.get_derivees_() + dt * spin.f());
}
