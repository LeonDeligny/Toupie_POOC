//
//  ConeSimple.hpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef ConeSimple_hpp
#define ConeSimple_hpp

#include "Toupieh.h"
#include <utility>
#include <cmath>
#include <stdio.h>
class ConeSimple : public Toupie {
private:
    const double masse_volumique_;
    const double hauteur_;
    const double rayon_;
    const double moment_dinertie1;
    const double moment_dinertie3;
    const double centre_de_masse;

public:
    ConeSimple(const Vecteur& cond_ini, Vecteur deri_cond_ini, const Vecteur& angle, const double mv,
               const double h, const double r)
            :Toupie(cond_ini, std::move(deri_cond_ini), angle, 1.0/3.0 * M_PI * mv * r * r * h, 3), masse_volumique_(mv),
             hauteur_(h), rayon_(r),
             moment_dinertie1((3.0*masse)/20.0 *(r*r + 0.25 * h*h)),
             moment_dinertie3((3.0*masse)/10.0 * r*r), centre_de_masse(0.75 * h) { }
    std::ostream& affiche(std::ostream& sortie);

};
#endif /* ConeSimple_hpp */

#endif //TOUPIE_CONESIMPLE_H