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

class Contenu : public Dessinable {
public:
  Contenu(SupportADessin* vue)
    : Dessinable(vue), angle(0.0)
  {}
  virtual ~Contenu() {}

  virtual void dessine() override
  { support->dessine(*this); }

  void evolue(double dt);
    
double infos() const { return angle; }

private:
  double angle;
};


#endif /* Contenu_hpp */
