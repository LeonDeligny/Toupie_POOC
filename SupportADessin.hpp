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
class Contenu;
class Toupie;
class Systeme;
class ConeSimple;
class Memoire;

class SupportADessin {
public:
    virtual ~SupportADessin() = default;
    // on supposera ici que les supports ne sont ni copiés ni déplacés
    virtual void dessine(Contenu const& a_dessiner) = 0;
    virtual void dessine(Toupie const& a_dessiner) = 0;
    virtual void dessine(Systeme const& a_dessiner) = 0;
    virtual void dessine(ConeSimple const& a_dessiner) = 0;
    virtual void dessine(Memoire const& a_dessiner) = 0;

    // ... autres choses que vous voudriez dessiner...
};
#endif /* SupportADessin_hpp */
