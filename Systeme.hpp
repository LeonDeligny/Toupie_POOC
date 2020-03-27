#pragma once
#ifndef Systeme_hpp
#define Systeme_hpp

#include <cstdio>
#include <memory>
#include <iostream>
#include "Toupie.h"
#include "Dessinable.hpp"
#include "Integrateur.h"
#include "SupportADessin.hpp"

std::ostream& operator<<(std::ostream& cout, const std::vector<std::unique_ptr<Toupie>>& systeme);

class Systeme : public Dessinable{
private:
    std::vector<std::unique_ptr<Toupie>> systeme;
    Integrateur* integrateur;
public:
    Systeme(SupportADessin* supp, std::vector<std::unique_ptr<Toupie>> systeme1, Integrateur* i1)
    : Dessinable(supp), systeme(std::move(systeme1)), integrateur(i1) {}
    void ajoute(std::unique_ptr<Toupie> t) {
        systeme.push_back(std::move(t));
    }
    void dessine() override { support->dessine(*this); }

    void evolue();

};


#endif /* Systeme_hpp */