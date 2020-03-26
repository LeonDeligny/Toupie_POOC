//
//  Integrateur.hpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Integrateur_hpp
#define Integrateur_hpp

#include <stdio.h>
#include "Toupieh.h"

class Integrateur{
public:
    void evolue(Toupie& spin, const double& dt);
};

#endif /* Integrateur_hpp */