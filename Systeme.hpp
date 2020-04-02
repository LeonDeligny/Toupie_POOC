#pragma once
#ifndef Systeme_hpp
#define Systeme_hpp

#include <cstdio>
#include "Integrateur.h"

class Systeme : public Dessinable{
private:
    std::vector<std::unique_ptr<Toupie>> systeme;
    Integrateur* integrateur;
public:
    Systeme(SupportADessin* supp, std::vector<std::unique_ptr<Toupie>> systeme1, Integrateur* i1)
    : Dessinable(supp), systeme(std::move(systeme1)), integrateur(i1) {}
    void ajoute(const Toupie& satourne) {
        systeme.push_back(satourne.copie());
    }
    void dessine() override { support->dessine(*this); }

    void evolue();

};

std::ostream& operator<<(std::ostream& sortie, const std::vector<std::unique_ptr<Toupie>>& systeme);

#endif /* Systeme_hpp */