//
//  TextViewer.cpp
//  POO
//
//  Created by Léon Deligny on 26/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#include <iostream>
#include "TextViewer.hpp"
#include "Contenu.hpp"

void TextViewer::dessine(Contenu const&){
    flot << "un cube" << std::endl;
}

void TextViewer::dessine(Toupie const &a_dessiner) {
    flot << "Une toupie" << std::endl;
}

void TextViewer::dessine(Systeme const &a_dessiner) {
    flot<< " Un systeme" << std::endl;
}

void TextViewer::dessine(ConeSimple const &a_dessiner) {
    flot << "Un cone simple" << std::endl;
}

