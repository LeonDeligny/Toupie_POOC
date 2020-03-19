#include <utility>
#include <cmath>

#include "Toupieh.h"


class ConeSimple : public Toupie{
private:
    const double masse_volumique_;
    const double hauteur_;
    const double rayon_;
    const double m;
    const double moment_dinertie1;
    const double moment_dinertie3;

public:
    ConeSimple(Vecteur cond_ini, Vecteur deri_cond_ini, const double mv,
               const double h, const double r)
               :Toupie(std::move(cond_ini), std::move(deri_cond_ini)), masse_volumique_(mv),
            hauteur_(h), rayon_(r), m(1/3 * M_PI * mv * r * r * h),
            moment_dinertie1((3*m)/20 *(r*r + 0.25 * h*h)),
            moment_dinertie3((3*m)/10 * r*r) { }
};
#ifndef TOUPIE_CONESIMPLE_H
#define TOUPIE_CONESIMPLE_H

#endif //TOUPIE_CONESIMPLE_H
