//
//  IntegrateurEulerCromer.cpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#include "IntegrateurEuler-Cromer.h"

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const double& dt) {
    spin.set_vitesses(spin.get_vitesses_() + dt * spin.f(spin.get_position(), spin.get_vitesses_()));
    spin.set_position(spin.get_position() + dt * spin.get_vitesses_());
}