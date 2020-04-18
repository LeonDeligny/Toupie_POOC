#include "IntegrateurEulerCromer.hpp"
#include <iostream>
using namespace std;

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const double& dt) {
    /*Les formules viennent du complément mathématique, le corps de la fonction f() est dans la classe
    conesimple.
    les deux cout plus bas sont là pour simplifier une méthode de la classe systeme, et donc rajoutés 
    bien plus tardivement.*/
    spin.set_derivees(spin.get_derivees_() + dt * spin.f());
    
    spin.set_parametres(spin.get_parametres() + dt * spin.get_derivees_());

   cout << "parametres : " << spin.get_parametres();
    cout << " ; derivee : " << spin.get_derivees_() << endl;
}
