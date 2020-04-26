#pragma once
#ifndef TOUPIE_MATRICE33H_H
#define TOUPIE_MATRICE33H_H
#include <array>
#include "Vecteur.h"
#include "Vecteurdim3h.h"

typedef std::array<double, 3> ligne3;

class Matrice33 {
private:
    std::array<ligne3, 3> matrice{};
public :
    Matrice33(double a, double b, double c, double d, double e, double f, double g, double h, double i);
    Matrice33(); //matrice identitée
    Matrice33(double a, double e, double i):Matrice33(a, 0, 0, 0, e, 0, 0, 0, i) { } //matrice diagonale;
    Matrice33 transp();
    double det() const;
    Matrice33 inv() const;
    std::ostream& affiche_matrice33(std::ostream& sortie) const;
    Matrice33& operator+=(const Matrice33&);
    Matrice33& operator-=(const Matrice33&);
    Matrice33& operator*=(const double& d);
    const Vecteur operator*(const Vecteur& droit);
    double get_valeur(size_t ligne, size_t colonne) const {return matrice[ligne][colonne];}
    void set_valeur(size_t ligne, size_t colonne, double valeur){matrice[ligne][colonne]=valeur;}
};
std::ostream& operator<<(std::ostream& sortie, Matrice33 const& v);
const Matrice33 operator+(Matrice33 gauche, const Matrice33& droite);
const Matrice33 operator-(Matrice33 gauche, const Matrice33& droite);
const Matrice33 operator*(Matrice33 gauche, const Matrice33& droite);
const Matrice33 operator*(double d, const Matrice33& droite);
const Matrice33 operator*(Matrice33 gauche, const double& d);
#endif //TOUPIE_MATRICE33H_H
