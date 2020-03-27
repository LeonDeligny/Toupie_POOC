#include "ConeSimple.h"
#include <iostream>
using namespace std;
std::ostream& ConeSimple::affiche(std::ostream& sortie) {
    sortie << "Cone Simple " << endl;
    Toupie::affiche(sortie);
     sortie << "masse volumique (kg. m-3) : " << masse_volumique_ << endl
     << "hauteur (m) : " << hauteur_ << endl
     << "rayon (m) : " << rayon_ << endl;
    return sortie;
}