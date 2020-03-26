
#ifndef IntegrateurEulerCromer_hpp
#define IntegrateurEulerCromer_hpp

#include <stdio.h>
#include "Integrateur.h"

class Integrateur_Euler_Cromer : public Integrateur{
public:
    void evolue(Toupie &spin, const double& dt);
};
#endif /* IntegrateurEulerCromer_hpp */