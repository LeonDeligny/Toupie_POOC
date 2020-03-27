#include "Vecteur.h"
#include "Vecteurdim3h.h"
#include "Matrice33.h"
#include "Integrateur.h"
using namespace std;

int main() {

    try {
        Vecteur vect1;
        Vecteur vect2;
        Vecteur vect3;
        vect1.augmente(1.0);
        vect1.augmente(2.0);
        vect1.augmente(-0.1);
        vect2.augmente(2.6);
        vect2.augmente(2.5);
        vect2.augmente(-4.1);

        Matrice33 test(1, 2, 3);
        cout<<test;
        Matrice33 id;
        cout<<test - id;

        
    }
    catch(string& erreur){
        cout<<endl;
        cerr<<"Erreur : "<<erreur<<" impossible."<<endl;
    }
    return 0;
}

