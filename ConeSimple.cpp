//
//  ConeSimple.cpp
//  POO
//
//  Created by Léon Deligny on 19/03/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#include "ConeSimple.h"
#include <iostream>
using namespace std;
std::ostream& ConeSimple::affiche(std::ostream& sortie) {
    sortie << "Cone Simple " << endl << "paramètre : " << angles << std::endl << "derivée : " << vitesses_ << endl << "masse volumique (kg. m-3) : " << masse_volumique_ << endl << "hauteur (m) : " << hauteur_ << endl << "rayon (m) : " << rayon_ << "origine (A) : " << position_ << endl;
    return sortie;
}
