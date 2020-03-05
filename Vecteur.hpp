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
#include <iostream>
#include <vector>
class Vecteur {
private:
    std::vector<double> vecteur;
public:
    void augmente(double const& valeur);
    void set_coord(int const& position, double const& valeur);
    void affiche();
    std::vector<double> get_vecteur() const;
    bool compare(Vecteur const &v) ;
    Vecteur addition(Vecteur autre) const;
    Vecteur oppose() const;
    Vecteur soustraction(Vecteur autre) const;
    Vecteur mult(double autre) const;
    double prod_scal(Vecteur autre) const;
    double norme() const;
    double norme2() const;

};

#endif /* Vecteur_hpp */
