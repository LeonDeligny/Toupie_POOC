#include <iostream>
#include "Vecteurh.h"
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

        vect3 = vect1.addition(vect2);
        vect3.affiche();

        Vecteur v_;
        v_.augmente(6);
        vect1.addition(v_); //Ca ne marche pas :)

        vect3.affiche(); //n'est pas affiché :)
        
    }
    catch(string& erreur){
        cout<<endl;
        cerr<<erreur<<endl;
    }

    /*
    (1.0, 2.0, -0.1) + (2.6, 3.5, 4.1) = (3.6, 5.5, 4.0)
    l'addition du vecteur nul de même dimension (c.-à-d. (0, 0, 0) pas le vecteur de dimension nulle !) ne fait rien (1.0, 2.0, -0.1) - (2.6, 3.5, 4.1) = (-1.6, -1.5, -4.2)
    la soustraction d'un vecteur à lui-même donne le vecteur nul (de même dimension !)
    vérifiez votre choix pour les opérations entre vecteurs de dimensions différentes (cf question P1.2)
    l'opposé de (1.0, 2.0, -0.1) est (-1.0, -2.0, 0.1) l'addition d'un opposé est égal à la soustraction
    3 * (1.0, 2.0, -0.1) = (3.0, 6.0, -0.3)
    (1.0, 2.0, -0.1) * (2.6, 3.5, 4.1) = 9.19
    (1.0, 2.0, -0.1) ^ (2.6, 3.5, 4.1) = (8.55, -4.36, -1.7) ||(1.0, 2.0, -0.1)||^2 = 5.01
    ||(2.6, 3.5, 4.1)||^2
     */
    return 0;
}

