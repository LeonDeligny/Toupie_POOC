//
//  Dessinable.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Dessinable_hpp
#define Dessinable_hpp

#include <stdio.h>
#include "SupportADessin.hpp"
#include <iostream>
class Dessinable {
private:
    SupportADessin* s;
public:
    virtual void dessine() = 0;
    std::ostream& affiche(std::ostream& sortie);
    Dessinable(SupportADessin* s1) : s(s1) {}
};

#endif /* Dessinable_hpp */
