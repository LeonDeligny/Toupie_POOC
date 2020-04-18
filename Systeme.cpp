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
    cout<<"Le systeme est constitue des "<< ensemble.size() <<" toupies suivantes (independantes)  :" << endl;
    unsigned int taille(1);
    for(auto const& spin : ensemble){
        cout <<"=== Toupie "<<taille<<" : "<< endl;
        cout << *spin;
        taille += 1;
    }
    taille=1;
    /*Affiche le nombre de toupies et leurs caractéristiques.*/

    cout<<endl;
    cout << "Le systeme evolue et se dessine a chaque pas (dt=0.01) : " << endl;
    //Appel la méthode évolue et appel la méthode évolue() de l'intégrateur tour à tour.
    //Le choix de l'arrêter après 10 itérations est arbitaire.
    float t(0.01);
    do {
        cout << endl << "t = " << t << endl;
        for (auto const &turn : ensemble) {
            cout << endl << "dessin de la toupie " << taille << endl;

            integrateur->evolue(*turn, 0.01); //l'affichage se fait dans evolue(turn, 0.01)
            taille += 1;
        }
        t += 0.01;
        taille=1;
    }while(t < 0.1);
}
