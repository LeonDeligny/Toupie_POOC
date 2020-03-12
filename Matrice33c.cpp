//
// Created by alexa on 12/03/2020.
//
#include <vector>
#include "Vecteurh.h"
#include "Matrice33h.h"
#include "Vecteurdim3h.h"
using namespace std;

Matrice33 Matrice33::transp(){
    vector<Vecteur_dim3> m_;
    Vecteur_dim3 v1, v2, v3;
    v1 = {matrice[0].get_vecteur()[0], matrice[1].get_vecteur()[0], matrice[2].get_vecteur()[0]};
    v2 = { matrice[0].get_vecteur()[1], matrice[1].get_vecteur()[1], matrice[2].get_vecteur()[1]};
    v3 = { matrice[0].get_vecteur()[2], matrice[1].get_vecteur()[2], matrice[2].get_vecteur()[2]};
    m_.push_back(v1);
    m_.push_back(v2);
    m_.push_back(v3);
    Matrice33 m(m_);
    return m;
}

double Matrice33::det() const{
    return( matrice[0].get_vecteur()[0] * ( matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[2] - matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[1] )
            - ( matrice[0].get_vecteur()[1] * ( matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[2] - matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[0]))
            + matrice[0].get_vecteur()[2] * ( matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[1] - matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[0]) );
}

Matrice33 Matrice33::inv() const {
    Vecteur_dim3 v1, v2, v3;
    double const a(Matrice33::det());
    v1 = { 1/a * (matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[2] -  matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[1]),
           1/a * (matrice[0].get_vecteur()[2] * matrice[2].get_vecteur()[1] -  matrice[0].get_vecteur()[1] * matrice[2].get_vecteur()[2]),
           1/a * (matrice[0].get_vecteur()[1] * matrice[1].get_vecteur()[2] -  matrice[0].get_vecteur()[2] * matrice[1].get_vecteur()[1])};

    v2 = { 1/a * (matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[0] -  matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[2]),
           1/a* (matrice[0].get_vecteur()[0] * matrice[2].get_vecteur()[2] -  matrice[0].get_vecteur()[2] * matrice[2].get_vecteur()[0]),
           1/a* ( matrice[0].get_vecteur()[2] * matrice[1].get_vecteur()[0] - matrice[0].get_vecteur()[0] * matrice[1].get_vecteur()[2] )};

    v3 = { 1/a * (matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[1] -  matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[0]),
           1/a* (matrice[0].get_vecteur()[1] * matrice[2].get_vecteur()[0] -  matrice[0].get_vecteur()[0] * matrice[2].get_vecteur()[1]),
           1/a * (matrice[0].get_vecteur()[0] * matrice[1].get_vecteur()[1] -  matrice[0].get_vecteur()[1] * matrice[1].get_vecteur()[0])};
    vector<Vecteur_dim3> m_;
    m_.push_back(v1);
    m_.push_back(v2);
    m_.push_back(v3);
    Matrice33 mat(m_);
    return mat;
}

ostream& Matrice33::affiche_matrice33(ostream& sortie) const {
    for (int i(0); i < 3; ++i) {
        for ( int j(0); j < 3; ++j) {
            sortie << matrice[i].get_vecteur()[j] << " ";
        }
        sortie << endl;
    }
    return sortie;
}
ostream& operator<<(ostream& sortie, Matrice33 const& v) {
    return v.affiche_matrice33(sortie);
}