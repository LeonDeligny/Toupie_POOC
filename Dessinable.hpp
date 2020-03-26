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
#include <iostream>
#include "SupportADessin.hpp"

class Dessinable {
public:
 Dessinable(SupportADessin* support) : support(support) {}
 virtual ~Dessinable() {}
 virtual void dessine() = 0;

protected:
 /* Nous mettons un pointeur au lieu d'une référence *
  * au cas où l'on voudrait changer de support (non  *
  * implémenté ici), ou même copier un dessinable,   *
  * échanger (swap) deux dessinables, etc.           *
  * Il n'est pas nécessaire d'implémenter une copie  *
  * profonde ici ; c'est bien une copie de surface   *
  * dont nous avons besoin.                          */
 SupportADessin* support;

};
#endif /* Dessinable_hpp */
