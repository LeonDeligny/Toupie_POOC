#include <iostream>
#include "TextViewer.hpp"
#include "Contenu.hpp"
#include "Toupie.h"
#include "ConeSimple.h"
#include "Systeme.hpp"

/*void TextViewer::dessine(Contenu const&){
    flot << "un cube" << std::endl;
}*/


//Textviewer permet simplement d'afficher les toupies, à part ou dans un système, exactement
//comme dans les classes respectives.
void TextViewer::dessine(Toupie const &toupie) {
    flot << "paramètres : "<< toupie.get_parametres();
}

void TextViewer::dessine(Systeme const &collection) {
    for(size_t i(0); i<collection.get_taille(); ++i){
        flot<<"la toupie "<<i<<" se dessine : ";
        collection.get_spinning_top(i)->dessine();
    }
}

void TextViewer::dessine(ConeSimple const &conesimple) {
    flot << "parametres : "<<conesimple.get_parametres();
    flot <<"; derivees : "<<conesimple.get_derivees_()<<std::endl;
}


