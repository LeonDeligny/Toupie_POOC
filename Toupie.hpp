//
//  Toupie.hpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Toupie_hpp
#define Toupie_hpp

#include <cstdio>
#include "Vecteur.hpp"
#include "Dessinable.hpp"
#include "SupportADessin.hpp"
#include <memory>
#include <string>
#include <utility>
#include <memory>

extern const Vecteur g;

class Toupie : public Dessinable {
protected:
    Vecteur parametres;
    Vecteur derivees;
    double masse;
    unsigned int degre_de_liberte_;
public:
    Toupie(Vecteur cond_ini, Vecteur deri_cond_ini, double m, SupportADessin* supp, unsigned int degl=5):
            Dessinable(supp), parametres(std::move(cond_ini)), derivees(std::move(deri_cond_ini)),
            degre_de_liberte_(degl), masse(m) { }
    virtual ~Toupie() {};
    virtual Vecteur f();

    Vecteur get_parametres () const {
        return parametres;
    };
    void set_parametres(const Vecteur& pos_) {parametres = pos_; };
    Vecteur get_derivees_() const {return derivees;};
    void set_derivees(const Vecteur& vit) {derivees = vit;};

    std::unique_ptr<Toupie> clone() const {return std::make_unique<Toupie>(*this);}
    virtual std::unique_ptr<Toupie> copie() const {return clone();}

    virtual std::ostream& affiche(std::ostream&) const ;
    void dessine() override { support->dessine(*this); }
};
std::ostream& operator<<(std::ostream& cout, const Toupie& spin);


#endif /* Toupie_hpp */
