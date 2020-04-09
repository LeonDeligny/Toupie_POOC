#include <cmath>
#include "Systeme.hpp"
#include "ConeSimple.h"
#include "IntegrateurEuler-Cromer.h"

using namespace std;

int main() {

    SupportADessin* support(nullptr);

    Vecteur parametre({ 0.0, M_PI/6, 0.0});
    Vecteur derivee({0.0, 0.0, 60.0});


    auto* integrateur(new Integrateur_Euler_Cromer);

    ConeSimple test1(parametre, derivee, 0.1, 1.5, 0.5, support);

    Vecteur parametre1({0.0, M_PI/4, 0.0});
    Vecteur derivee1({0.0, 0.0, 40.0});

    ConeSimple test2(parametre1, derivee1, 0.1, 1.5, 0.5, support);

    vector<unique_ptr<Toupie>> tableau;

    Systeme systeme(support, integrateur);

    systeme.ajoute(test1);
    systeme.ajoute(test2);

    systeme.evolue();
    return 0;
}
