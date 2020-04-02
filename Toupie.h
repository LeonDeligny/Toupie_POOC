#pragma once
#ifndef Toupie_hpp
#define Toupie_hpp

#include <cstdio>
#include "Vecteur.h"
#include "Dessinable.hpp"
#include "SupportADessin.hpp"
#include <memory>
#include <string>
#include <memory>

extern const Vecteur g;

class Toupie : public Dessinable {
protected:
    Vecteur position_;
    Vecteur angles;
    Vecteur vitesses_;
    double masse;
    unsigned int degre_de_liberte_;
public:
    Toupie(Vecteur cond_ini, const Vecteur& angle,  Vecteur deri_cond_ini, unsigned int m, SupportADessin* supp, unsigned int degl=5):
            Dessinable(supp), position_(std::move(cond_ini)), vitesses_(std::move(deri_cond_ini)),
            degre_de_liberte_(degl), masse(m) { }

    Vecteur f(const Vecteur& P, const Vecteur& P_prime);

    Vecteur get_position () const {return position_;};
    void set_position(const Vecteur& pos_) {position_ = pos_; };
    Vecteur get_vitesses_() const {return vitesses_;};
    void set_vitesses(const Vecteur& vit) {vitesses_ = vit;};

    std::unique_ptr<Toupie> clone() const {return std::make_unique<Toupie>(*this);}
    virtual std::unique_ptr<Toupie> copie() const {return clone();}

    virtual std::ostream& affiche(std::ostream&) const ;
    void dessine() override { support->dessine(*this); }
};
std::ostream& operator<<(std::ostream& cout, const Toupie& spin);


#endif /* Toupie_hpp */


#ifndef TOUPIE_TOUPIEH_H
#define TOUPIE_TOUPIEH_H

#endif //TOUPIE_TOUPIEH_H
