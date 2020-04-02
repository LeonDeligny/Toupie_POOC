#ifndef Integrateur_hpp
#define Integrateur_hpp

#include <cstdio>
#include "Toupie.h"

class Integrateur{
public:
    virtual void evolue(Toupie& spin, const double& dt);
};

#endif /* Integrateur_hpp */