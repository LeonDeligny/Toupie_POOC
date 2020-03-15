#pragma once
#ifndef Vecteurh_h
#define Vecteurh_h

#include <vector>
#include <initializer_list>
#include <iostream>

class Vecteur {
protected:
    std::vector<double> vecteur;
public:
    explicit Vecteur(std::vector<double>  R = {}): vecteur(std::move(R)) {}
    void augmente(double const& valeur);
    void set_coord(size_t const& position, double const& valeur);
    std::vector<double> get_vecteur() const;
    bool operator==(Vecteur const &v)const ;
    std::ostream& affiche(std::ostream&) const ;
    Vecteur& operator+=(Vecteur const&) ;
    Vecteur& operator-=(Vecteur const&) ;
    const Vecteur operator^(Vecteur const&) const ;
    const Vecteur operator~()const ;
    Vecteur& operator*=(const double&);
    double operator*(Vecteur const& autre) const;
    double norme() const;
    double norme2() const;

};

std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);
Vecteur& operator-(const Vecteur&);
const Vecteur operator-(Vecteur a, const Vecteur& b);
const Vecteur operator+(Vecteur a, const Vecteur& b);
const Vecteur operator*(Vecteur a, const double& d);
const Vecteur operator*(double d, const Vecteur& a);

#endif /* Vecteurh_h */
