#pragma once
#include "Vecteurh.h"
extern const Vecteur g;

class Toupie{
private:
    Vecteur parametres_;
    Vecteur derivee_parametre_;

public:
    Toupie(Vecteur cond_ini, Vecteur deri_cond_ini):
    parametres_(std::move(cond_ini)), derivee_parametre_(std::move(deri_cond_ini)) { }
    Vecteur f(const Vecteur& P, const Vecteur& P_prime);

    std::ostream& affiche(std::ostream&) const ; //j'ai pas trop compris ce qu'on est censé afficher


};


#ifndef TOUPIE_TOUPIEH_H
#define TOUPIE_TOUPIEH_H

#endif //TOUPIE_TOUPIEH_H
