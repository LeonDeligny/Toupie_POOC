//
//  memoire.cpp
//  POO
//
//  Created by Léon Deligny on 30/04/2020.
//  Copyright © 2020 Léon Deligny. All rights reserved.
//

#include "memoire.hpp"
#include "Toupie.hpp"
#include <deque>
#include <cmath>
using namespace std;

void Memoire::evolue() {
    cout<<"Le systeme est constitue des "<< ensemble.size() <<" toupies suivantes (independantes)  :" << endl;
    unsigned int taille(1);
    for(auto const& spin : ensemble){
        cout <<"=== Toupie "<<taille<<" : "<< endl;
        cout << *spin;
        taille += 1;
    }
    taille=1;
    cout << endl << "Le systeme evolue et se dessine a chaque pas (dt=0.01) : " << endl;
    float t(0.01);
    std::deque<Vecteur> point_de_contact;
    std::deque<Vecteur> centre_de_masse;
    
    double a((3.0/4.0)* (*ensemble[0]).get_hauteur());
    do {
        cout << endl << "t = " << t << endl;
        for (auto const &turn : ensemble) {
            cout << endl << "dessin de la toupie " << taille << endl;
            double psi = (*ensemble[0]).get_parametres().get_vecteur()[0];
            double theta = (*ensemble[0]).get_parametres().get_vecteur()[1];
            //double phi = (*ensemble[0]).get_parametres().get_vecteur()[2];

            Vecteur OG({sin(theta)*sin(psi)*a, -sin(theta)*cos(psi)*a, cos(theta)*a});
            centre_de_masse.push_back(OG);
            
            integrateur->evolue(*turn, 0.01); //l'affichage se fait dans evolue(turn, 0.01)
            taille += 1;
        }
        t += 0.01;
        taille=1;
    }while(t < 0.1);

       std::cout << "Les positions du point du centre de masse sont :";
    for (std::deque<Vecteur>::iterator it = centre_de_masse.begin(); it!=centre_de_masse.end(); ++it) {
       std::cout << ' ' << *it;
    }
     std::cout << '\n';

}
