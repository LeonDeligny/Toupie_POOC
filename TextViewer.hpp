//
//  TextViewer.hpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#ifndef TextViewer_hpp
#define TextViewer_hpp

#include <stdio.h>
#include "SupportADessin.hpp"
#include <iostream>

class Contenu;
class Toupie;
class Systeme;
class ConeSimple;
class Dessinable;

class TextViewer : public SupportADessin{
public:
    TextViewer(std::ostream& flot)
    :flot(flot) { }

   virtual  ~TextViewer() { }

    void dessine(Contenu const& a_dessiner) override;
    void dessine(Toupie const& a_dessiner) override;
    void dessine(Systeme const& a_dessiner) override;
    void dessine(ConeSimple const& a_dessiner) override;

private:
    std::ostream& flot;

};
#endif /* TextViewer_hpp */
