#include "Toupie.h"
using std::cout;
using std::endl;

Vecteur Toupie::f(const Vecteur &P, const Vecteur &P_prime) {
    Vecteur _P(P); //P-point-point

    return _P; //Le corps viendra plus tard
}

std::ostream &Toupie::affiche(std::ostream& sortie) const {
    sortie << "angle : " << angles << endl;
    sortie << "derivee : " << vitesses_ << endl;
    sortie << "origine : " << position_ << endl;

    return sortie;
}

std::ostream& operator<<(std::ostream& exit, const Toupie& spin){
    return spin.affiche(exit);
}