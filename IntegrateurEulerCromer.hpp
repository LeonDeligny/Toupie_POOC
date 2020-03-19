//
//  IntegrateurEulerCromer.hpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef IntegrateurEulerCromer_hpp
#define IntegrateurEulerCromer_hpp

#include <stdio.h>
#include "Integrateur.hpp"

class Integrateur_Euler_Cromer : public Integrateur{
public:
    void evolue(Toupie &spin, const double& dt);
};
#endif /* IntegrateurEulerCromer_hpp */
