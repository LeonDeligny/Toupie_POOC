#include <iostream>
#include "TextViewer.hpp"
#include "Contenu.hpp"

void TextViewer::dessine(Toupie const &a_dessiner) {
    flot << "paramètres : " << a_dessiner.get.parametres();
}

void TextViewer::dessine(Systeme const &a_dessiner) {
    ensemble.dessiner(flot);
    /* for (size_t i(0); i<ensemble.get_size(); ++i){
    flot << "dessin de la toupie " << i << " : ";
    ensemble.get_toupie(i)->dessine();
    }*/
}

void TextViewer::dessine(ConeSimple const &a_dessiner) {
    flot << "parametres : " << a_dessiner.get_parametres();
         <<"; derivees : " << a_dessiner.get_derivees()<<std::endl;
}

