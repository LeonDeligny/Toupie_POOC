#include "Vecteur.hpp"
#include <iostream>
#include <cmath>
using namespace std;

vector<double> Vecteur::get_vecteur() const { return vecteur; }

bool Vecteur::operator==(Vecteur const &v) const {
    if (v.vecteur.size() == vecteur.size()) {
        for (size_t i(0); i < vecteur.size(); ++i) {
            if (v.vecteur[i] != vecteur[i]) {
                return false;
            }
        }
    } else {
        return false;
    }
    return true;
}

void Vecteur::augmente(double const &valeur) { vecteur.push_back(valeur); }

void Vecteur::set_coord(size_t const &position, double const &valeur) {
    if (vecteur.size() > position) {
        vecteur[position] = valeur;
    } else {
        size_t m(position - vecteur.size() + 1);
        for (size_t i(0); i < m; ++i) {
            vecteur.push_back(0);
        }
        vecteur[position] = valeur;
    }
}

Vecteur Vecteur::operator+(Vecteur const &autre) const {
    Vecteur v_;
    if (vecteur.size() != autre.vecteur.size()) {
        throw"Erreur : tableaux de tailles différentes, addition impossible."s;
    } else if (vecteur.empty() or autre.vecteur.empty()) {
        throw"Erreur : tableau vide, addition impossible."s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            v_.set_coord(i, autre.vecteur[i] + vecteur[i]);
        }
    }
    return v_;
}

Vecteur Vecteur::operator-() const {
    Vecteur v_;
    if (vecteur.empty()) {
        throw"Erreur : tableau vide, inversion des signes impossible."s;
    }
    for (size_t i(0); i < vecteur.size(); ++i) {
        v_.set_coord(i, -vecteur[i]);
    }
    return v_;
}

Vecteur Vecteur::operator-(Vecteur const &autre) const {
    Vecteur v_;
    if (vecteur.size() != autre.vecteur.size() and !vecteur.empty()) {
        throw"Erreur : tableaux de tailles différentes, soustraction impossible.";
    } else if (vecteur.empty() or autre.vecteur.empty()) {
        throw"Erreur: tableau vide, soustraction impossible."s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            v_.set_coord(i, vecteur[i] - autre.vecteur[i]);
        }
    }
    return v_;
}

Vecteur Vecteur::operator*(double const &autre) {
    Vecteur v_;
    if (vecteur.empty()) {
        throw"Erreur, tableau vide, multiplication par un scalaire impossible."s;
    } else {
        for (int i(0); i< vecteur.size(); ++i) {
            v_.set_coord(i, autre*vecteur[i]);
        }
    }
    return v_;
}

double Vecteur::operator*(Vecteur const &autre) const {
    double a(0);
    if (vecteur.empty() or autre.vecteur.empty()) {
        throw"Erreur : tableau vide, produit scalaire impossible."s;
        return 0;
    } else if (vecteur.size() != autre.vecteur.size()) {
        throw"Erreur : tableaux de dimension differente, produit scalaire impossible."s;
        return 0;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            a += vecteur[i] * autre.vecteur[i];
        }
    }
    return a;
}

double Vecteur::norme() const {
    double a(0);
    if (vecteur.empty()) {
        throw"Erreur : tableau vide, calcul de la norme euclidienne impossible."s;
        return 0;
    } else {
        for (double i : vecteur) {
            a += i * i;
        }
    }
    return sqrt(a);
}

double Vecteur::norme2() const {
    double a(0);
    if (vecteur.empty()) {
        throw"Erreur : tableau vide, calcul de la norme^2 impossible."s;
        return 0;
    } else {
        for (double i : vecteur) {
            a += i * i;
        }
    }
    return a;
}

Vecteur Vecteur::operator~() {
    const double n(Vecteur::norme());
    if (n != 0) {
        for (double &i : vecteur) {
            i = i / n;
        }
    }
    return *this;
}

Vecteur Vecteur::operator^(Vecteur const &autre) const {
    Vecteur v_;
    if (autre.vecteur.size() == 3 and vecteur.size() == 3) {
        v_.vecteur[0] = vecteur[1] * autre.vecteur[2] - vecteur[2] * autre.vecteur[1];
        v_.vecteur[1] = vecteur[2] * autre.vecteur[0] - vecteur[0] * autre.vecteur[2];
        v_.vecteur[2] = vecteur[0] * autre.vecteur[1] - vecteur[1] * autre.vecteur[0];
    }
    return v_;
}

Matrice33 Matrice33::transp() const{
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
    return( matrice[0].get_vecteur()[0] * ( matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[2] - matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[1] ) - ( matrice[0].get_vecteur()[1] * ( matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[2] - matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[0])) + matrice[0].get_vecteur()[2] * ( matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[1] - matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[0]) );
}

Matrice33 Matrice33::inv() const {
    Vecteur_dim3 v1, v2, v3;
    double const a(Matrice33::det());
    v1 = { 1/a * (matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[2] -  matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[1]), 1/a * (matrice[0].get_vecteur()[2] * matrice[2].get_vecteur()[1] -  matrice[0].get_vecteur()[1] * matrice[2].get_vecteur()[2]), 1/a * (matrice[0].get_vecteur()[1] * matrice[1].get_vecteur()[2] -  matrice[0].get_vecteur()[2] * matrice[1].get_vecteur()[1])};
    
    v2 = { 1/a * (matrice[1].get_vecteur()[2] * matrice[2].get_vecteur()[0] -  matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[2]), 1/a* (matrice[0].get_vecteur()[0] * matrice[2].get_vecteur()[2] -  matrice[0].get_vecteur()[2] * matrice[2].get_vecteur()[0]),
       1/a* ( matrice[0].get_vecteur()[2] * matrice[1].get_vecteur()[0] - matrice[0].get_vecteur()[0] * matrice[1].get_vecteur()[2] )};
    
    v3 = { 1/a * (matrice[1].get_vecteur()[0] * matrice[2].get_vecteur()[1] -  matrice[1].get_vecteur()[1] * matrice[2].get_vecteur()[0]), 1/a* (matrice[0].get_vecteur()[1] * matrice[2].get_vecteur()[0] -  matrice[0].get_vecteur()[0] * matrice[2].get_vecteur()[1]), 1/a * (matrice[0].get_vecteur()[0] * matrice[1].get_vecteur()[1] -  matrice[0].get_vecteur()[1] * matrice[1].get_vecteur()[0])};
    vector<Vecteur_dim3> m_;
    m_.push_back(v1);
    m_.push_back(v2);
    m_.push_back(v3);
    Matrice33 mat(m_);
    return mat;
}
ostream& Vecteur::affiche(ostream& sortie) const {
    for (auto const& i: vecteur) {
        sortie << i << " ";
    }
    return sortie;
}
ostream& operator<<(ostream& sortie, Vecteur const& v) {
    return v.affiche(sortie);
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
