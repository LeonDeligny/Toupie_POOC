//
// Created by alexa on 19/03/2020.
//
#include "IntegrateurEuler-Cromer.h"

void Integrateur_Euler_Cromer::evolue(Toupie &spin, const unsigned short int& dt) {
    spin.set_vitesses(spin.get_vitesses_() + dt * spin.f(spin.get_position(), spin.get_vitesses_()));
    spin.set_position(spin.get_position() + dt * spin.get_vitesses_());
}
