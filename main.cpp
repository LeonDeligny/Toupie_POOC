#include <iostream>
#include <vector>
#include "Vecteur.hpp"
#include "matrice33.hpp"
#include "ConeSimple.hpp"
#include "Integrateur.hpp"
#include "IntegrateurEulerCromer.hpp"
#include "Toupie.hpp"
#include "SupportADessin.hpp"
#include "Systeme.hpp"
#include "Dessinable.hpp"
using namespace std;

int main() {

    try {
        Vecteur v1({0,0,0});
        Vecteur v2({10, 9 , 8});
        Vecteur v3({1, 4, 5});
        ConeSimple t(v1, v2 , v3, 3, 4, 5);
        SupportADessin* so;
        unique_ptr<ConeSimple> v(new ConeSimple (t));
        vector<unique_ptr<ConeSimple>> s;
        s.push_back(std::move(v));
        Integrateur* i;
        Systeme u(so, s, i);

    }
    catch(string& erreur){
        cout<<endl;
        cerr<<erreur<<endl;
    }
    return 0;
}
