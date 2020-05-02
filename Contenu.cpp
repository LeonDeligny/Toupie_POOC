//
//  Contenu.cpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#include "Contenu.hpp"

void Contenu::evolue(double dt)
{
  constexpr double omega(100.0);
  angle += omega * dt;
}
