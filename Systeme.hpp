#ifndef Systeme_hpp
#define Systeme_hpp

#include <cstdio>
#include <memory>
#include <iostream>
#include "Toupieh.h"
#include "Dessinable.hpp"
#include "Integrateur.h"
std::ostream& operator<<(std::ostream& cout, const std::vector<std::unique_ptr<Toupie>>& systeme);

class Systeme : public Dessinable, public Contenu { //sans l'héritage multiple, dessine ne compile pas
private:
    std::vector<std::unique_ptr<Toupie>> systeme;
    Integrateur* i;
public:
    Systeme(SupportADessin* s, std::vector<std::unique_ptr<Toupie>> systeme1, Integrateur* i1)
    : Dessinable(s), systeme(std::move(systeme1)), i(i1) {}
    void ajoute(std::unique_ptr<Toupie> t) {
        systeme.push_back(std::move(t));
    }
    void dessine() override { support->dessine(*this); }

    }

};


#endif /* Systeme_hpp */