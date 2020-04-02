#include "ConeSimple.h"
using std::endl;

std::ostream& ConeSimple::affiche(std::ostream& sortie) const{
    sortie << "Cone Simple " << endl;
    Toupie::affiche(sortie);
     sortie << "masse volumique (kg. m-3) : " << masse_volumique_ << endl
     << "hauteur (m) : " << hauteur_ << endl
     << "rayon (m) : " << rayon_ << endl;
    return sortie;
}

Vecteur ConeSimple::f(const Vecteur &P, const Vecteur &P_prime) {
    return Vecteur((1/))
}
