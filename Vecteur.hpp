//
//  Vecteur.hpp
//  POO
//
//  Created by Léon Deligny on 27/02/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Vecteur_hpp
#define Vecteur_hpp

#include <stdio.h>
#include <utility>
#include <vector>
#include <initializer_list>
class Vecteur {
protected:
    std::vector<double> vecteur;
public:
    explicit Vecteur(std::vector<double>  R = {0}): vecteur(std::move(R)) {}
    //Explicit : pour des constructeurs à
    void augmente(double const& valeur);                          //un argument-> optimisation, pareil pour le move
    void set_coord(size_t const& position, double const& valeur);
    std::vector<double> get_vecteur() const;
    bool operator==(Vecteur const &v)const ;
    std::ostream& affiche(std::ostream& sortie) const ;
    Vecteur operator+(Vecteur const& autre) const ;
    Vecteur operator-() const ;
    Vecteur operator-(Vecteur const& autre) const ;
    Vecteur operator*(double const& autre) ;
    Vecteur operator^(Vecteur const& autre ) const ;
    Vecteur operator~();
    double operator*(Vecteur const& autre) const;
    double norme() const;
    double norme2() const;
};
std::ostream& operator<<(std::ostream& sortie, Vecteur const& v);

class Vecteur_dim3 : public Vecteur {
public:
    Vecteur_dim3(double x = 0, double y = 0, double z = 0) : Vecteur({x, y, z}) {}
};

class Matrice33 {
private:
    std::vector<Vecteur_dim3> matrice;
public:
    explicit Matrice33(std::vector<Vecteur_dim3> R) : matrice(std::move(R)) {}
    Matrice33 transp() const;
    double det() const;
    Matrice33 inv() const;
    std::ostream& affiche_matrice33(std::ostream& sortie) const;
};
std::ostream& operator<<(std::ostream& sortie, Matrice33 const& v);

#endif /* Vecteur_hpp */
