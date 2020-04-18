//
// Created by alexa on 12/03/2020.
//
#include "Vecteur.h"
#include "Matrice33.h"
#include "Vecteurdim3h.h"
#include <iomanip>
#include<cmath>
using namespace std;

Matrice33 Matrice33::transp(){
    
    /*Nous avons décidé de retourner une nouvelle matrice, puisqu'il s'agit, selon nous, d'une autre matrice que
    la matrice originale. La nouvelle matrice est ainsi construite grâce à un constructeur de la classe.*/

    Matrice33 transpo(matrice[0][0], matrice[1][0], matrice[2][0],
                      matrice[0][1], matrice[1][1], matrice[2][1],
                      matrice[0][2], matrice[1][2], matrice[2][2]);

    return transpo;
}

double Matrice33::det() const{
    /* Nous aurions pu écrire une formule plus générale, afin qu'elle s'adapte si jamais la classe matrice33
    devient par exemple matrice44, mais le calcul du déterminant devenant vite compliqué pour de grandes matrices,
    et puisqu'il ne s'agit pas là d'un point crucial du projet, nous avons décidé de nous limiter au déterminant 
    d'une matrice 3x3.*/
    return matrice[0][0] * (matrice[1][1] * matrice[2][2] - matrice[1][2] * matrice[2][1])
         - matrice[0][1] * (matrice[1][0] * matrice[2][2] - matrice[1][2] * matrice[2][0])
         + matrice[0][2] * (matrice[1][0] * matrice[2][1] - matrice[1][1] * matrice[2][0]);
}

Matrice33 Matrice33::inv() const {
    /* Nous faisons bien évidemment appel à la méthode det(), et appelons le constructeur pour créer une nouvelle
    matrice, que nous divisons par la déterminant, opération rendue possible grâce à la surcharge de la multiplication.*/
    double const a(Matrice33::det());
    if (abs(a)<1e-5){return Matrice33 (0,0,0);}
    Matrice33 inv(matrice[1][1] * matrice[2][2] - matrice[1][2] * matrice[2][1],
                  matrice[0][2] * matrice[2][1] - matrice[0][1] * matrice[2][2],
                  matrice[0][1] * matrice[1][2] - matrice[0][2] * matrice[1][1],

                  matrice[1][2] * matrice[2][0] - matrice[1][0] * matrice[2][2],
                  matrice[0][0] * matrice[2][2] - matrice[0][2] * matrice[2][0],
                  matrice[0][2] * matrice[1][0] - matrice[0][0] * matrice[1][2],

                  matrice[1][0] * matrice[2][1] - matrice[1][1] * matrice[2][0],
                  matrice[0][1] * matrice[2][0] - matrice[0][0] * matrice[2][1],
                  matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0]);
    return 1/a * inv;
}

ostream& Matrice33::affiche_matrice33(ostream& sortie) const {
    /*Une méthode nécessaire à la surcharge de l'opérateur d'affichage <<. Nous avons choisi de faire comme
    dans les exercices, à l'aide de boucles, qui, elles, seraient compatibles avec des matrices d'autres tailles.*/
    sortie << "[ ";
    setprecision(5);
    sortie.setf(ios::showpoint);
    for (size_t i(0); i < matrice.size(); ++i) {
        if (i > 0) { sortie << " "; }
        sortie << "(";
        for (size_t j(0); j < matrice[i].size(); ++j) {
            sortie << matrice[i][j];
            if (j < matrice[i].size() -1) { sortie << "  "; }
            else {
                sortie << ")";
                if (i < matrice.size() - 1) { sortie << endl << " "; }
            }
        }
    }
    sortie << "  ]";
    sortie << endl << endl;
    return sortie;
}

Matrice33::Matrice33(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    //Ce constructeur permet d'éviter de devoir passer par la création peu naturelle de tableaux pour créer une matrice
    matrice ={{a, b, c},
              {d, e, f},
              {g, h, i}};
    {}

}

Matrice33 &Matrice33::operator+=(const Matrice33 &add) {
    for(size_t i(0); i<matrice.size(); ++i){
        for(size_t j(0); j<matrice[i].size(); ++j){
            matrice[i][j]+=add.matrice[i][j];
        }
    }
    return *this;
}

Matrice33 &Matrice33::operator-=(const Matrice33 &sub) {
    for(size_t i(0); i<matrice.size(); ++i) {
        for (size_t j(0); j < matrice[i].size(); ++j) {
            matrice[i][j] -= sub.matrice[i][j];
        } //J'aurais bien écrit return *this += (-1) * sub;
    } //Mais la multiplication par un scalaire aurait créée une copie inutile
    return *this; 
}

Matrice33& Matrice33::operator*=(const Matrice33 & prod) {
    /*La syntaxe peut paraître confuse au premier regard à cause de la variable locale, mais elle
    permet de conserver les valeurs des coefficients la matrice au milieu de la boucle.
    L'opérateur += donnait des résultats faux.*/
    for (auto & i : matrice) {
        for (size_t j(0); j < i.size(); ++j) {
            for (size_t k(0); k <=j; ++k) {
                double a = i[j];
                i[j]=0;
                i[j] = a + i[k] * prod.matrice[k][j];
            }
        }
    }
    return *this;
}

Matrice33 &Matrice33::operator*=(const double &d) {
    for(auto & i : matrice){
        for(double & j : i){
            j*=d;
        }
    }
    return *this;
}

const Vecteur Matrice33::operator*(const Vecteur &droit) {
    /*Les exceptions écrites dans le code permettent d'éviter des opérations non voulues, pouvant
    être provoquées par des erreurs d'inattention. Nous avons préféré cette option plutôt que de perdre
    du temps dans un potentiel debugging.*/
    if(droit.get_vecteur().size() != matrice[0].size()){
        throw"multiplication matrice-vecteur"s;
    }
    Vecteur v_;
    for(size_t i(0); i<matrice.size(); ++i){
        double a(0);
        v_.augmente(0);
        for(size_t j(0); j<droit.get_vecteur().size(); ++j){
            a += matrice[i][j] * droit.get_vecteur()[j];
        }
        v_.set_coord(i, a);
    }
    return v_;
}

Matrice33::Matrice33() {
    /*Construit la matrice identité, ce qui semble logique pour un constructeur par défaut.*/
    matrice = {{1, 0, 0},
               {0, 1, 0},
               {0, 0, 1}};
    {}
}

ostream& operator<<(ostream& sortie, Matrice33 const& v) {
    //C'est pour cette surcharge que la méthode affiche existe.
    return v.affiche_matrice33(sortie);
}

const Matrice33 operator+(Matrice33 gauche, const Matrice33 &droite) {
    //Tous les opérateurs +=, -=, etc, ont été surchargés pour garantir l'encapsulation de ces opérateurs ci.
    return gauche+=droite;
}

const Matrice33 operator-(Matrice33 gauche, const Matrice33 &droite) {
    return gauche-=droite;
}

const Matrice33 operator*(Matrice33 gauche, const Matrice33 &droite) {
    return gauche*=droite;
}

const Matrice33 operator*(double d, const Matrice33 &droite) {
    return Matrice33 (droite)*=d;
}

const Matrice33 operator*(Matrice33 gauche, const double &d) {
    return gauche*=d;
}
