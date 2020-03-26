//
//  SupportADessin.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef SupportADessin_hpp
#define SupportADessin_hpp

#include <stdio.h>
#include "ConeSimple.hpp"
#include "Contenu.hpp"
class SupportADessin {
    public:
    virtual ~SupportADessin() {}
    // on supporsera ici que les supports ne sont ni copiés ni déplacés
    virtual void dessine(Contenu const& a_dessiner) = 0;
    // ... autres choses que vous voudriez dessiner...
};

#endif /* SupportADessin_hpp */
