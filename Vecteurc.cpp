#include "Vecteurh.h"
#include <cmath>
#include <iomanip>
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
        size_t m(position - vecteur.size());
        for (size_t i(0); i <= m; ++i) {
            vecteur.push_back(0);
        }
        vecteur[position] = valeur;
    }
}

Vecteur& operator-(Vecteur& v_) {
    return v_ *= (-1);
}

Vecteur& Vecteur::operator-=(Vecteur const &autre) {
    if (vecteur.size() != autre.vecteur.size() and !vecteur.empty()) {
        throw "tableaux de tailles différentes, soustraction";
    } else if (vecteur.empty() or autre.vecteur.empty()) {
        throw "tableau vide, soustraction"s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            vecteur[i] -= autre.vecteur[i];
        }
    }
    return *this;
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

const Vecteur operator-(Vecteur a, const Vecteur &b) {
    return a-=b;
}

const Vecteur operator+(Vecteur a, const Vecteur &b) {
    return a+=b;
}

const Vecteur operator*(Vecteur a, const double &d) {
    return a*=d;
}

const Vecteur operator*(double d, const Vecteur &a) {
    return Vecteur( a ) *=d;
}

ostream& Vecteur::affiche(ostream& sortie) const {
    sortie << "(";
    setprecision(5);
    sortie.setf(ios::showpoint);
    for (auto const& i: vecteur) {
       sortie << i << " ";
    }
    sortie << ")";
    return sortie;
}

Vecteur& Vecteur::operator*=(const double& lambda) {
    for(auto& el : vecteur){
        el *= lambda;
    }
    return *this;
}

Vecteur &Vecteur::operator+=(Vecteur const & autre) {
        if (vecteur.size() != autre.vecteur.size()) {
            throw"tableaux de tailles différentes, addition"s;
        } else if (vecteur.empty() or autre.vecteur.empty()) {
            throw"tableau vide, addition"s;
        } else {
            for (size_t i(0); i < vecteur.size(); ++i) {
                vecteur[i]+=autre.vecteur[i];
            }
        }
        return *this;
    }

