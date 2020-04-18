#include "Vecteur.hpp"
#include <cmath>
#include <iomanip>
using namespace std;

vector<double> Vecteur::get_vecteur() const { return vecteur; }

bool Vecteur::operator==(Vecteur const &v) const {
    /*La méthode vérifie que les vecteurs sont de même taille, sinon retourne false tout de suite.
    Ensuite, elle parcourt les vecteurs, et retourne false dès qu'une différence est trouvée.
    Elle retourne true si les deux autres tests n'ont rien retourné avant.*/
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
//Nous avons naturellement utilisé la méthode push_back des vector.

void Vecteur::set_coord(size_t const &position, double const &valeur) {
    /*Si le vecteur est assez grand, la valeur est directement modifiée à la position voulue.
    Sinon, la taille du vecteur augmente, et ce dernier se remplit de zéros jusqu'à ce qu'il soit assez grand.*/
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
    //Retourne le vecteur opposé
    return v_ *= (-1);
}

Vecteur& Vecteur::operator-=(Vecteur const &autre) {
    /*Nous avons choisi de lancer des exceptions afin de voir tout de suite d'où provient l'erreur
    si nous en déclenchons une par inadvertance. Ici, nous vérifions que la soustraction est mathématiquement
    concevable, et faisons ensuite une simple itération sur le vecteur.
    Les autres surcharges d'opérateur sont similaires. */
    if (vecteur.size() != autre.vecteur.size() and !vecteur.empty()) {
        throw "tableaux de tailles différentes, soustraction"s;//Le 's' permet de faire comprendre au compilateur que c'est une string
    } else if (vecteur.empty() or autre.vecteur.empty()) {
        throw "tableau vide, soustraction"s;
    } else {
        for (size_t i(0); i < vecteur.size(); ++i) {
            vecteur[i] -= autre.vecteur[i];
        }
    }
    return *this;
    
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
}

Vecteur& Vecteur::operator*=(const double& lambda) {
    //Multiplication d'un vecteur par un scalaire.
    for(auto& el : vecteur){
        el *= lambda;
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
    //Permet d'éviter la duplication du code.
}

double Vecteur::norme2() const {
    return Vecteur(*this)*Vecteur(*this);
    //Nous nous servons ici de la surcharge de l'opérateur *. Les copies sont nécessaires.
}

const Vecteur Vecteur::operator~() const {
    return Vecteur(*this)*(1/norme());
}

const Vecteur Vecteur::operator^(Vecteur const &autre) const {
    Vecteur v_;
    if (autre.get_vecteur().size() == 3 and get_vecteur().size() == 3) {
        v_.set_coord(0, vecteur[1] * autre.vecteur[2] - vecteur[2] * autre.vecteur[1]);
        v_.set_coord(1, vecteur[2] * autre.vecteur[0] - vecteur[0] * autre.vecteur[2]);
        v_.set_coord(2,vecteur[0] * autre.vecteur[1] - vecteur[1] * autre.vecteur[0]) ;
  }
    return v_;
}

ostream& Vecteur::affiche(ostream& sortie) const {
    //Nous avons choisi de représenter les vecteurs comme il est coutume de le faire en mathématiques :
    //entre parenthèses et sans virgules.
    sortie << "(";
    setprecision(5);
    sortie.setf(ios::showpoint);//permet d'afficher 5 décimales.
    for (auto const& i: vecteur) {
       sortie << i << " ";
    }
    sortie << ")";
    return sortie;
}

ostream& operator<<(ostream& sortie, Vecteur const& v) {
    //La fonction affiche permet de simplifier le corps de cette fonction.
    return v.affiche(sortie);
}
//Nous nous servons de la surcharge des opérateurs *=, etc, pour garder l'encapsulation.
const Vecteur operator-(Vecteur a, const Vecteur &b) {
    return a-=b;
}

const Vecteur operator+(Vecteur a, const Vecteur &b) {
    return a+=b;
}

//Les deux fonctions en dessous permettent la multiplication par un scalaire à gauche et à droite.
const Vecteur operator*(Vecteur a, const double &d) {
    return a*=d;
}

const Vecteur operator*(double d, const Vecteur &a) {
    return Vecteur(a) *=d;
}
