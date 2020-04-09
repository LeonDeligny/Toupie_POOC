#pragma once
#ifndef TOUPIE_CONTENU_HPP
#define TOUPIE_CONTENU_HPP

#include "Dessinable.hpp"
#include "SupportADessin.hpp"

class Contenu : public Dessinable
{
public:
    Contenu(SupportADessin* vue)
            :Dessinable(vue) { }

    virtual ~Contenu() = default;

    void dessine() override {support->dessine(*this); }
};


#endif //TOUPIE_CONTENU_HPP