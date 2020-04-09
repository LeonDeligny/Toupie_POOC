#include <iostream>
#include <math.h>
#include "TextViewer.hpp"
#include "Dessinable.hpp"
#include "Contenu.hpp"
#include "Vecteur.h"
#include "IntegrateurEuler-Cromer.h"
#include "ConeSimple.h"
#include "Systeme.hpp"

using namespace std;

int main(){
    TextViewer ecran(cout);

    Vecteur parametre({ 0.0, M_PI/6, 0.0});
    Vecteur derivee({0.0, 0.0, 60.0});

    ConeSimple test1(parametre, derivee, 0.1, 1.5, 0.5, &ecran);

    Vecteur parametre1({0.0, M_PI/4, 0.0});
    Vecteur derivee1({0.0, 0.0, 40.0});

    ConeSimple test2(parametre1, derivee1, 0.1, 1.5, 0.5, &ecran);

    ecran.dessine(test1);

    return 0;

}


