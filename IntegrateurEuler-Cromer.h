#pragma once
#ifndef IntegrateurEulerCromer_hpp
#define IntegrateurEulerCromer_hpp

#include <cstdio>
#include "Integrateur.h"

class Integrateur_Euler_Cromer : public Integrateur{
public:
    void evolue(Toupie &spin, const double& dt) override;
};
#endif /* IntegrateurEulerCromer_hpp */