#include "Vecteurh.h"
#include <iostream>
#include <cmath>
#include <vector>
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

const Vecteur Vecteur::operator+(Vecteur const &autre) const {
    Vecteur v_;
    if (vecteur.size() != autre.vecteur.size()) {
        throw"tableaux de tailles différentes, addition"s;
    } else if (vecteur.empty() or autre.vecteur.empty()) {
        throw"tableau vide, addition"s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            v_.set_coord(i, autre.vecteur[i] + vecteur[i]);
        }
    }
    return v_;
}

const Vecteur Vecteur::operator-() const {
    Vecteur v_;
    if (vecteur.empty()) {
        throw"tableau vide, inversion des signes"s;
    }
    for (size_t i(0); i < vecteur.size(); ++i) {
        v_.set_coord(i, -vecteur[i]);
    }
    return v_;
}

const Vecteur Vecteur::operator-(Vecteur const &autre) const {
    Vecteur v_;
    if (vecteur.size() != autre.vecteur.size() and !vecteur.empty()) {
        throw"tableaux de tailles différentes, soustraction";
    } else if (vecteur.empty() or autre.vecteur.empty()) {
        throw"tableau vide, soustraction"s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            v_.set_coord(i, vecteur[i] - autre.vecteur[i]);
        }
    }
    return v_;
}

double Vecteur::operator*(Vecteur const &autre) const {
    double a(0.0);
    if (vecteur.empty() or autre.vecteur.empty()) {
        throw"tableau vide, produit scalaire"s;
    } else if (vecteur.size() != autre.vecteur.size()) {
        throw"tableaux de dimension differente, produit scalaire"s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            a += vecteur[i] * autre.vecteur[i];
        }
    }
    return a;
}

double Vecteur::norme() const {
    return sqrt(norme2());
}

double Vecteur::norme2() const {
    return Vecteur(*this)*Vecteur(*this);
}

const Vecteur Vecteur::operator~() const {
    return Vecteur(*this)*(1/norme());
}

const Vecteur Vecteur::operator^(Vecteur const &autre) const {
    Vecteur v_;
    if (autre.vecteur.size() == 3 and vecteur.size() == 3) {
        v_.vecteur[0] = vecteur[1] * autre.vecteur[2] - vecteur[2] * autre.vecteur[1];
        v_.vecteur[1] = vecteur[2] * autre.vecteur[0] - vecteur[0] * autre.vecteur[2];
        v_.vecteur[2] = vecteur[0] * autre.vecteur[1] - vecteur[1] * autre.vecteur[0];
    }
    return v_;
}

ostream& operator<<(ostream& sortie, Vecteur const& v) {
    return v.affiche(sortie);
}

ostream& Vecteur::affiche(ostream& sortie) const {
    for (auto const& i: vecteur) {
       sortie << i << " ";
    }
    return sortie;
}

Vecteur& Vecteur::operator*=(double lambda) {
    for(auto& el : vecteur){
        el *= lambda;
    }
    return *this;
}

