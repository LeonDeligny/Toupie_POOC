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
#include "Contenu.hpp"
#include <iostream>
class TextViewer : public SupportADessin {
    TextViewer(std::ostream& flot) : flot(flot) {}
     virtual ~TextViewer() {}
     virtual void dessine(Contenu const& a_dessiner) override;
private:
     std::ostream& flot;
};

#endif /* TextViewer_hpp */
