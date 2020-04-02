#include "Systeme.hpp"
#include "Toupie.h"
using std::cout;
using std::endl;
std::ostream& operator<<(std::ostream& sortie, const std::vector<std::unique_ptr<Toupie>>& systeme) {
    for( auto const& element : systeme ) {
        element->affiche(sortie);
    }
    return sortie;
}

void Systeme::evolue() {
    cout<<"Le systeme est constitué des"<< systeme.size() <<"toupies suivantes (indépendantes)  :" << endl;
    unsigned int taille(1);
    for(auto const& spin : systeme){
        cout <<"=== Toupie "<<taille<<" : "<< endl;
        cout << *spin;
        taille += 1;
    }
    taille=1;

    cout << "Le système évolue et se dessine à chaque pas (dt=0.01) : " << endl;
    float t(0.0);
    do {
        for (auto const &turn : systeme) {
            cout << "t = " << t << endl;
            cout << "dessin de la toupie" << taille;
            integrateur->evolue(*turn, 0.01); //l'affichage se fait dans evolue(turn, 0.01)
            taille += 1;
        }
        t += 0.01;
    }while(t < 0.1);
}
