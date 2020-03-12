#pragma once
#ifndef Vecteurh_h
#define Vecteurh_h

#include <cstdio>
#include <utility>
#include <vector>
#include <initializer_list>
#include <iostream>

class Vecteur {
protected:
    std::vector<double> vecteur;
public:
    explicit Vecteur(std::vector<double>  R = {0}): vecteur(std::move(R)) {}
    void augmente(double const& valeur);
    void set_coord(size_t const& position, double const& valeur);
    std::vector<double> get_vecteur() const;
    bool operator==(Vecteur const &v)const ;
    std::ostream& affiche(std::ostream&) const ;
    const Vecteur operator+(Vecteur const&) const ;
    const Vecteur operator-() const ;
    const Vecteur operator-(Vecteur const&) const ;
    const Vecteur operator^(Vecteur const&) const ;
    const Vecteur operator~()const ;
    Vecteur& operator*=(double);
    double operator*(Vecteur const& autre) const;
    double norme() const;
    double norme2() const;

};

std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);

#endif /* Vecteurh_h */
