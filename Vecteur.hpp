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
#include <vector>
#include <initializer_list>
class Vecteur {
private:
    std::vector<double> vecteur;
public:
    Vecteur(std::vector<double> const& R = {0}): vecteur(R) {}
    void augmente(double const& valeur);
    void set_coord(size_t const& position, double const& valeur);
    void affiche() const ;
    bool compare(Vecteur const &v)const ;
    
    Vecteur addition(Vecteur const& autre) const ;
    Vecteur oppose() const ;
    Vecteur soustraction(Vecteur const& autre) const ;
    Vecteur mult(double const& autre) ;
    Vecteur prod_vectoriel(Vecteur const& autre ) const ;
    Vecteur unitaire();
    double prod_scal(Vecteur const& autre) const;
    double norme() const;
    double norme2() const;

};

#endif /* Vecteur_hpp */
