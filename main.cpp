#include <iostream>
#include "Vecteur.hpp"
#include "matrice33.hpp"
#include "ConeSimple.hpp"
#include "Integrateur.hpp"
#include "IntegrateurEulerCromer.hpp"
#include "Toupie.hpp"
#include "TestIntegrateur.hpp"
#include "TestToupie.hpp"
using namespace std;

int main() {

    try {
        Vecteur v1({0,0});
        Vecteur v2({1.1,2.4});
        Toupie spin(v1, v2, 0,127);
        Toupie spin1(v1, v2, 0,127);
        Integrateur i;
        Integrateur_Euler_Cromer s;
        s.evolue(spin1, 0.1);
        s.evolue(spin1, 0.3);
        i.evolue(spin, 0.1);
        i.evolue(spin, 0.3);
        cout << spin << endl;
        cout << spin1 << endl;
    }
    catch(string& erreur){
        cout<<endl;
        cerr<<erreur<<endl;
    }
    return 0;
}
