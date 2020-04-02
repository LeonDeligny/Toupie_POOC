#include <cmath>
#include "Systeme.hpp"
#include "ConeSimple.h"
#include "IntegrateurEuler-Cromer.h"

using namespace std;

int main() {

    SupportADessin* support(nullptr);

    Vecteur angle1({0, M_PI/6, 0});
    Vecteur position1({0.0, 0.0, 0.0});
    Vecteur dericondini1({0, 0, 60.0});

    auto* integrateur(new Integrateur_Euler_Cromer);

    ConeSimple test1(position1, angle1, dericondini1, 0.1, 1.5, 0.5, support);

    Vecteur angle2({0, M_PI/4, 0.0});
    Vecteur dericondini2({0, 0, 40.0});
    Vecteur position2({0.1, 0.0, 0.0});

    ConeSimple test2(position2, angle2, dericondini2, 0.1, 1.5, 0.5, support);

    vector<unique_ptr<Toupie>> tableau;

    Systeme systeme(support, integrateur);

    systeme.ajoute(test1);
    systeme.ajoute(test2);

    systeme.evolue();

    return 0;
}
