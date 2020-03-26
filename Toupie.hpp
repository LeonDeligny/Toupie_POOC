//
//  Toupie.hpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Toupie_hpp
#define Toupie_hpp

#include <stdio.h>
#include "Vecteur.hpp"
extern const Vecteur g;

class Toupie {
protected:
    Vecteur position_;
    Vecteur angles;
    Vecteur vitesses_;
    unsigned int degre_de_liberte_;
    unsigned int masse;
public:
    Toupie(Vecteur cond_ini, Vecteur deri_cond_ini, Vecteur angle, unsigned int m, unsigned int degl=5):
    position_(std::move(cond_ini)), vitesses_(std::move(deri_cond_ini)),
    degre_de_liberte_(degl), masse(m) { }

    Vecteur f(const Vecteur& P, const Vecteur& P_prime);

    Vecteur get_position () const {return position_;};
    void set_position(const Vecteur& pos_) {position_ = pos_; };
    Vecteur get_vitesses_() const {return vitesses_;};
    void set_vitesses(const Vecteur& vit) {vitesses_ = vit;};

    std::ostream& affiche(std::ostream&) const ; //j'ai pas trop compris ce qu'on est censé afficher
};
std::ostream& operator<<(std::ostream& cout, const Toupie& spin);


#endif /* Toupie_hpp */
