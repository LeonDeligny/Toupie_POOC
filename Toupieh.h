#pragma once
#include "Vecteurh.h"
extern const Vecteur g;

class Toupie{
private:
    Vecteur position_;
    Vecteur vitesses_;
    unsigned int degre_de_liberte_;

public:
    Toupie(Vecteur cond_ini, Vecteur deri_cond_ini, unsigned int degl=5):
    position_(std::move(cond_ini)), vitesses_(std::move(deri_cond_ini)),
    degre_de_liberte_(degl) { }

    Vecteur f(const Vecteur& P, const Vecteur& P_prime);

    Vecteur get_position () const {return position_;};
    void set_position(const Vecteur& pos_) {position_ = pos_; };
    Vecteur get_vitesses_() const {return vitesses_;};
    void set_vitesses(const Vecteur& vit) {vitesses_ = vit;};

    std::ostream& affiche(std::ostream&) const ; //j'ai pas trop compris ce qu'on est censé afficher


};


#ifndef TOUPIE_TOUPIEH_H
#define TOUPIE_TOUPIEH_H

#endif //TOUPIE_TOUPIEH_H
