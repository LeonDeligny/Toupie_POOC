//
//  Contenu.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Contenu_hpp
#define Contenu_hpp

#include "Dessinable.hpp"
#include "SupportADessin.hpp"

class Contenu : public Dessinable
{
public:
    Contenu(SupportADessin* supp)
            :Dessinable(supp) { }

    virtual ~Contenu() = default;

    void dessine() override {support->dessine(*this); }
};

#endif /* Contenu_hpp */
