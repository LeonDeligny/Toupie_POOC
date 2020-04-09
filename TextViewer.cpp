#include <iostream>
#include "TextViewer.hpp"
#include "Contenu.hpp"

void TextViewer::dessine(Toupie const &toupie) {
    flot << "paramètres : " << toupie.getparametres();
}

void TextViewer::dessine(Systeme const &toupies) {
    toupies.dessiner(flot);
    /* for (size_t i(0); i<ensemble.get_size(); ++i){
    flot << "dessin de la toupie " << i << " : ";
    ensemble.get_toupie(i)->dessine();
    }*/
}

void TextViewer::dessine(ConeSimple const &conesimple) {
    flot << "parametres : " << conesimple.get_parametres();
    flot <<"; derivees : " << conesimple.get_derivees_()<<std::endl;
}

//Rien ne compile
