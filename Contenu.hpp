//
//  Contenu.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef Contenu_hpp
#define Contenu_hpp

#include <stdio.h>
#include "SupportADessin.hpp"
#include "Dessinable.hpp"
class Contenu : public Dessinable {
    public:
      Contenu(SupportADessin* vue) : Dessinable(vue)
      {}
      virtual ~Contenu() {}
      virtual void dessine() override { support->dessine(*this); }
};
     
#endif /* Contenu_hpp */
