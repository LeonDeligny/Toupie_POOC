#pragma once
#ifndef ConeSimple_hpp
#define ConeSimple_hpp

#include "Toupie.h"
#include "Dessinable.hpp"
#include "SupportADessin.hpp"
#include <utility>
#include <cmath>
#include <cstdio>
class ConeSimple : public Toupie{
private:
    const double masse_volumique_;
    const double hauteur_;
    const double rayon_;
    const double moment_dinertie1;
    const double moment_dinertie3;
    const double centre_de_masse;

public:
    ConeSimple(const Vecteur& cond_ini, const Vecteur& angle, Vecteur deri_cond_ini, const double mv,
               const double hauteur, const double rayon, SupportADessin* support)
            :Toupie(cond_ini, angle, std::move(deri_cond_ini), 1.0/3.0 * M_PI * mv * rayon * rayon * hauteur, support, 3),
            masse_volumique_(mv), hauteur_(hauteur), rayon_(rayon),
             moment_dinertie1((3.0*masse)/20.0 *(rayon*rayon + 0.25 * hauteur*hauteur)),
             moment_dinertie3((3.0*masse)/10.0 * rayon*rayon), centre_de_masse(0.75 * hauteur) { }

             std::ostream& affiche(std::ostream& sortie);

    void dessine() override { support->dessine(*this); }
    std::ostream& affiche(std::ostream&) const override;

};
#endif /* ConeSimple_hpp */