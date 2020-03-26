#include "Toupieh.h"
using namespace std;

Vecteur Toupie::f(const Vecteur &P, const Vecteur &P_prime) {
    Vecteur _P(P); //P-point-point

    return _P; //Le corps viendra plus tard
}

std::ostream &Toupie::affiche(std::ostream& sortie) const {
    sortie << Toupie::get_position();
    return sortie;
}

std::ostream& operator<<(ostream& exit, const Toupie& spin){
    return spin.affiche(exit);
}