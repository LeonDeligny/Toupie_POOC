#include "Vecteur.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

    void Vecteur::augmente(double const& valeur) { vecteur.push_back(valeur); } //augmente la taille d'un vecteur
    
    void Vecteur::set_coord(size_t const& position, double const& valeur) {
        if ( vecteur.size() > position ) {
            vecteur[position] = valeur; //Ajoute une valeur si le vecteur est assez grand
        } else {
            size_t m(position - vecteur.size() + 1); //crée une case supplémentaire sinon
            for (size_t i(0); i < m ; ++i) {
                vecteur.push_back(0);
            }
            vecteur[position] = valeur;
        }
    }
    void Vecteur::affiche() {
        for (size_t i(0); i < vecteur.size() ; ++i ) {
            cout << vecteur[i] << " ";
        }
    }
    vector<double> Vecteur::get_vecteur() const { return vecteur; }
   
    bool Vecteur::compare(Vecteur const &v) { //indique si les vecteurs sont identiques
        bool a(true);
        if ( v.get_vecteur().size() == vecteur.size() ) {
            for ( size_t i(0); i < vecteur.size(); ++i ) {
                if ( v.get_vecteur()[i] != vecteur[i] ) {
                    a = false;
                }
            }
        } else {
            a = false;
        }
        return a;
    }
    
    Vecteur Vecteur::addition(const Vecteur& autre) const { //retourne un vecteur qui contient la somme des coordonnées
        Vecteur v_;
        if( vecteur.size() != autre.get_vecteur().size()) { //du vecteur de l'appel et de celui passé par référence constante
            cout << "Problème de dimension avec méthode addition ";
        
        } else if( vecteur.size() == 0 or autre.get_vecteur().size() == 0) {
            cout << "Utilisation de la méthode soustraction avec un vecteur vide ";
        
        } else {
            for ( size_t i(0); i < vecteur.size(); ++i) {
                v_.set_coord(i, autre.get_vecteur()[i] + vecteur[i]);
            }
        }
        return v_;
    }
    Vecteur Vecteur::oppose() const { //inverse les signes des valeurs d'un vecteur
        Vecteur v_;
        v_.set_coord(0, 0);
        if ( vecteur.size() == 0 ) {
            cout << "Utilisation de la méthode oppose avec un vecteur vide " << endl;
         
        } else {
            for( size_t i(0); i < vecteur.size(); ++i ) {
                v_.get_vecteur()[i] = -vecteur[i];
            }
        }
        return v_;
    }
    
    Vecteur Vecteur::soustraction(const Vecteur& autre) const {
        Vecteur v_;
        if( vecteur.size() != autre.get_vecteur().size() and vecteur.size() != 0) {
            cout << "Problème de dimension avec méthode soustraction ";
        } else if ( vecteur.size() == 0 or autre.get_vecteur().size() == 0) {
                cout << "Utilisation de la méthode soustraction avec un vecteur vide ";
        } else {
            for ( size_t i(0); i < vecteur.size(); ++i) {
                v_.get_vecteur()[i] = autre.get_vecteur()[i] - vecteur[i];
            }
        }
        return v_;
    }
    Vecteur Vecteur::mult(const double& autre) const {
        Vecteur v_;
        if ( vecteur.size() == 0 ) {
            cout << "Utilisation de la méthode mult avec un vecteur vide ";
            v_.get_vecteur()[0] = 0;
        } else {
            for( size_t i(0); i < vecteur.size(); ++i ) {
                v_.get_vecteur()[i] = autre * vecteur[i];
            }
        }
        return v_;
    }
    double Vecteur::prod_scal(const Vecteur& autre) const {
        double a(0);
        if ( vecteur.size() == 0 or autre.get_vecteur().size() == 0) {
            cout << "Utilisation de la méthode prod_scal avec un vecteur vide " << endl;
            return 0;
        } else if (vecteur.size() != autre.get_vecteur().size()) {
            cout << "Utilisation de la méthode prod_scal avec deux vecteurs dont les dimensions sont différentes " << endl;
            return 0;
        } else {
            for(size_t i(0); i < vecteur.size(); ++i ) {
                a += vecteur[i] * autre.get_vecteur().size();
            }
        }
        return a;
    }
    double Vecteur::normeuclide() const {
        double a(0);
        if ( vecteur.size() == 0) {
            cout << "Utilisation de la méthode norme avec un vecteur vide " << endl;
            return 0;
        } else {
            for( size_t i(0); i < vecteur.size(); ++i) {
                a += vecteur[i] * vecteur[i];
            }
        }
        return sqrt(a);
    }
    double Vecteur::norme2() const {
        double a(0);
        if ( vecteur.size() == 0) {
            cout << "Utilisation de la méthode norme2 avec un vecteur vide " << endl;
            return 0;
        } else {
            for( size_t i(0); i < vecteur.size(); ++i) {
                a += vecteur[i] * vecteur[i];
            }
        }
        return a;
    }
