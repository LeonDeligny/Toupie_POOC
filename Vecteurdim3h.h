//
// Created by alexa on 12/03/2020.
//
#pragma once
#ifndef TOUPIE_VECTEURDIM3H_H
#define TOUPIE_VECTEURDIM3H_H
#include"Vecteurh.h"

class Vecteur_dim3 : public Vecteur {
public:
    Vecteur_dim3(double x = 0, double y = 0, double z = 0) : Vecteur({x, y, z}) {}
};

#endif //TOUPIE_VECTEURDIM3H_H
