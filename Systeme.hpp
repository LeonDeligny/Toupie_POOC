#pragma once
#ifndef Systeme_hpp
#define Systeme_hpp

#include <cstdio>
#include "Integrateur.h"

class Systeme : public Dessinable{
private:
    std::vector<std::unique_ptr<Toupie>> ensemble;
    Integrateur* integrateur;
public:
    Systeme(SupportADessin* supp, Integrateur* i1)
    : Dessinable(supp), integrateur(i1) {}

    void ajoute(const Toupie& satourne) {
        ensemble.push_back(satourne.copie());
    }

    void dessine() override { support->dessine(*this); }

    void evolue();

};

std::ostream& operator<<(std::ostream& sortie, const std::vector<std::unique_ptr<Toupie>>& systeme);

#endif /* Systeme_hpp */