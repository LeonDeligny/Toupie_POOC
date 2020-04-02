#include "Toupie.hpp"
using std::cout;
using std::endl;

Vecteur Toupie::f() {
    Vecteur v({0});
    return v;
}

std::ostream &Toupie::affiche(std::ostream& sortie) const {
    sortie << "angle : " << parametres << endl;
    sortie << "derivee : " << derivees << endl;

    return sortie;
}

std::ostream& operator<<(std::ostream& exit, const Toupie& spin){
    return spin.affiche(exit);
}
