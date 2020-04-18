#include "Integrateur.hpp"
#include "Toupie.hpp"
using namespace std;
void Integrateur::evolue(Toupie& spin, const double& dt) {
    /*Le corps n'a rien de particulier, il s'agit de la formule du complément mathématique.
    On pourrait noter que cette méthode a créé la nécessité de créer de setters et des getters dans la classe toupie.*/
    spin.set_parametres(spin.get_parametres() + dt * spin.get_derivees_());
    spin.set_derivees(spin.get_derivees_() + dt * spin.f());
}
