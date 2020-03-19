//
// Created by alexa on 19/03/2020.
//
#pragma once
#ifndef TOUPIE_INTEGRATEUREULER_CROMER_H
#define TOUPIE_INTEGRATEUREULER_CROMER_H

#include "Integrateur.h"

class Integrateur_Euler_Cromer : public Integrateur{
public:
    void evolue(Toupie &spin, const unsigned short int& dt)
};

#endif //TOUPIE_INTEGRATEUREULER_CROMER_H
