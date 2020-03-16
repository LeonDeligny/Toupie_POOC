#include "matrice33.hpp"
#include <iomanip>
#include<cmath>
using namespace std;

Matrice33 Matrice33::transp(){

    Matrice33 transpo(matrice[0][0], matrice[1][0], matrice[2][0],
                      matrice[0][1], matrice[1][1], matrice[2][1],
                      matrice[0][2], matrice[1][2], matrice[2][2]);

    return transpo;
}

double Matrice33::det() const{
    return (matrice[0][0] * ( matrice[1][1] * matrice[2][2] - matrice[1][2] * matrice[2][1] )
         - (matrice[0][1] * ( matrice[1][0] * matrice[2][2] - matrice[1][2] * matrice[2][0]))
         + (matrice[0][2] * ( matrice[1][0] * matrice[2][1] - matrice[1][1] * matrice[2][0])));
}

Matrice33 Matrice33::inv() const {
    double const a(Matrice33::det());
    if (abs(a) < 1e-5){
        throw "Déterminant de valeur 0"s;
        return Matrice33 (0,0,0,0,0,0,0,0,0);}
    Matrice33 inv((matrice[1][1] * matrice[2][2] -  matrice[1][2] * matrice[2][1]),
            (matrice[0][2] * matrice[2][1] -  matrice[0][1] * matrice[2][2]),
            (matrice[0][1] * matrice[1][2] -  matrice[0][2] * matrice[1][1]),

            (matrice[1][2] * matrice[2][0] -  matrice[1][0] * matrice[2][2]),
            (matrice[0][0] * matrice[2][2] -  matrice[0][2] * matrice[2][0]),
            (matrice[0][2] * matrice[1][0] - matrice[0][0] * matrice[1][2] ),

            (matrice[1][0] * matrice[2][1] -  matrice[1][1] * matrice[2][0]),
             matrice[0][1] * matrice[2][0] -  matrice[0][0] * matrice[2][1],
            (matrice[0][0] * matrice[1][1] -  matrice[0][1] * matrice[1][0]));
    return 1/a * inv;
}

ostream& Matrice33::affiche_matrice33(ostream& sortie) const {
    sortie << "[ ";
    setprecision(5);
    sortie.setf(ios::showpoint);
    for (int i(0); i < 3; ++i) {
        if (i > 0) { sortie << " "; }
        sortie << "(";
        for (int j(0); j < 3; ++j) {
            sortie << matrice[i][j];
            if (j < 2) { sortie << "  "; }
            else {
                sortie << ")";
                if (i < 2) { sortie << endl << " "; }
            }
        }
    }
    sortie << "  ]";
    sortie << endl;
    return sortie;
}

Matrice33::Matrice33(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
    matrice ={{a, b, c},
              {d, e, f},
              {g, h, i}};
    {}

}

Matrice33 &Matrice33::operator+=(const Matrice33 &add) {
    for(size_t i(0); i<3; ++i){
        for(size_t j(0); j<3; ++j){
            matrice[i][j]+=add.matrice[i][j];
        }
    }
    return *this;
}

Matrice33 &Matrice33::operator-=(const Matrice33 &sub) {
    for(size_t i(0); i<3; ++i){
        for(size_t j(0); j<3; ++j){
            matrice[i][j]-=sub.matrice[i][j];
        }
    }
    return *this;
}

Matrice33& Matrice33::operator*=(const Matrice33 & prod) {
    for (size_t i(0); i < 3; ++i) {
        for (size_t j(0); j < 3; ++j) {
            for (size_t k(0); k < 3; ++k) {
                double a = matrice[i][j];
                matrice[i][j]=0;
                matrice[i][j] = a + matrice[i][k] * prod.matrice[k][j];
            }
        }
    }
    return *this;
}

Matrice33 &Matrice33::operator*=(const double &d) {
    for(size_t i(0); i<3; ++i){
        for(size_t j(0); j<3; ++j){
            matrice[i][j]*=d;
        }
    }
    return *this;
}

const Vecteur Matrice33::operator*(const Vecteur &droit) {
    if(droit.get_vecteur().size() != 3){
        throw"multiplication matrice-vecteur"s;
    }
    Vecteur v_;
    for(short int i(0); i<3; ++i){
        double a(0);
        v_.augmente(0);
        for(size_t j(0); j<3; ++j){
            a += matrice[i][j] * droit.get_vecteur()[j];
        }
        v_.set_coord(i, a);
    }
    return v_;
}

ostream& operator<<(ostream& sortie, Matrice33 const& v) {
    return v.affiche_matrice33(sortie);
}

const Matrice33 operator+(Matrice33 gauche, const Matrice33 &droite) {
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
