#define Vecteur_hpp

#include <stdio.h>
#include <utility>
#include <vector>
#include <initializer_list>
class Vecteur {
private:
    std::vector<double> vecteur;
public:
    explicit Vecteur(std::vector<double>  R = {0}): vecteur(std::move(R)) {} //Explicit : pour des constructeurs à
    void augmente(double const& valeur);                          //un argument-> optimisation, pareil pour le move
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

#ifndef TOUPIE_VECTEUR_H
#define TOUPIE_VECTEUR_H

#endif //TOUPIE_VECTEUR_H
