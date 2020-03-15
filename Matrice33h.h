#pragma once
#ifndef TOUPIE_MATRICE33H_H
#define TOUPIE_MATRICE33H_H
#include <array>
#include "Vecteurh.h"
#include "Vecteurdim3h.h"

typedef std::array<double, 3> ligne3;

class Matrice33 {
private:
    std::vector<ligne3> matrice;
public:
    explicit Matrice33(std::vector<ligne3> R) : matrice(std::move(R)) { }
    Matrice33(double a=1.0, double b=0.0, double c=0.0, double d=0.0, double e=1.0, double f=0.0, double g=0.0, double h=0.0, double i=1.0);
    Matrice33 transp();
    double det() const;
    Matrice33 inv() const;
    std::ostream& affiche_matrice33(std::ostream& sortie) const;
    Matrice33& operator+=(const Matrice33&);
    Matrice33& operator-=(const Matrice33&);
    Matrice33& operator*=(const Matrice33&);
    Matrice33& operator*=(const double& d);
    const Vecteur operator*(const Vecteur& droit);
};
std::ostream& operator<<(std::ostream& sortie, Matrice33 const& v);
const Matrice33 operator+(Matrice33 gauche, const Matrice33& droite);
const Matrice33 operator-(Matrice33 gauche, const Matrice33& droite);
const Matrice33 operator*(Matrice33 gauche, const Matrice33& droite);
const Matrice33 operator*(double d, const Matrice33& droite);
const Matrice33 operator*(Matrice33 gauche, const double& d);
#endif //TOUPIE_MATRICE33H_H
