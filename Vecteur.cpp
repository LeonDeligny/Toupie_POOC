#include "Vecteur.hpp"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

    void Vecteur::augmente(double const& valeur) { vecteur.push_back(valeur); }
    void Vecteur::set_coord(int const& position, double const& valeur) {
        if ( vecteur.size() > position ) {
            vecteur[position] = valeur;
        } else {
            unsigned long int m(position - vecteur.size() + 1);
            for (int i(0); i < m ; ++i) {
                vecteur.push_back(0);
            }
            vecteur[position] = valeur;
        }
    }
    void Vecteur::affiche() {
        for (int i(0); i < vecteur.size() ; ++i ) {
            cout << vecteur[i] << " ";
        }
    }
    vector<double> Vecteur::get_vecteur() const { return vecteur; }
    bool Vecteur::compare(Vecteur const &v) {
        bool a(true);
        if ( v.get_vecteur().size() == vecteur.size() ) {
            for ( int i(0); i < vecteur.size(); ++i ) {
                if ( v.get_vecteur()[i] != vecteur[i] ) {
                    a = false;
                }
            }
        } else {
            a = false;
        }
        return a;
    }
    Vecteur Vecteur::addition(Vecteur autre) const {
        Vecteur v_;
        if( vecteur.size() != autre.get_vecteur().size()) {
            cout << "Problème de dimension avec méthode addition ";
        } else if( vecteur.size() == 0 or autre.get_vecteur().size() == 0) {
            cout << "Utilisation de la méthode soustraction avec un vecteur vide ";
        } else {
            for ( int i(0); i < vecteur.size(); ++i) {
                v_.set_coord(i, autre.get_vecteur()[i] + vecteur[i]);
            }
        }
        return v_;
    }
    Vecteur Vecteur::oppose() const {
        Vecteur v_;
        if ( vecteur.size() == 0 ) {
            cout << "Utilisation de la méthode oppose avec un vecteur vide " << endl;
            v_.get_vecteur()[0] = 0;
        } else {
            for( int i(0); i < vecteur.size(); ++i ) {
                v_.get_vecteur()[i] = -vecteur[i];
            }
        }
        return v_;
    }
    Vecteur Vecteur::soustraction(Vecteur autre) const {
        Vecteur v_;
        if( vecteur.size() != autre.get_vecteur().size() and vecteur.size() != 0) {
            cout << "Problème de dimension avec méthode soustraction ";
        } else if ( vecteur.size() == 0 or autre.get_vecteur().size() == 0) {
                cout << "Utilisation de la méthode soustraction avec un vecteur vide ";
        } else {
            for ( int i(0); i < vecteur.size(); ++i) {
                v_.get_vecteur()[i] = autre.get_vecteur()[i] - vecteur[i];
            }
        }
        return v_;
    }
    Vecteur Vecteur::mult(double autre) const {
        Vecteur v_;
        if ( vecteur.size() == 0 ) {
            cout << "Utilisation de la méthode mult avec un vecteur vide ";
            v_.get_vecteur()[0] = 0;
        } else {
            for( int i(0); i < vecteur.size(); ++i ) {
                v_.get_vecteur()[i] = autre * vecteur[i];
            }
        }
        return v_;
    }
    double Vecteur::prod_scal(Vecteur autre) const {
        double a(0);
        if ( vecteur.size() == 0 or autre.get_vecteur().size() == 0) {
            cout << "Utilisation de la méthode prod_scal avec un vecteur vide " << endl;
            return 0;
        } else if (vecteur.size() != autre.get_vecteur().size()) {
            cout << "Utilisation de la méthode prod_scal avec deux vecteurs dont les dimensions sont différentes " << endl;
            return 0;
        } else {
            for(int i(0); i < vecteur.size(); ++i ) {
                a += vecteur[i] * autre.get_vecteur().size();
            }
        }
        return a;
    }
    double Vecteur::norme() const {
        double a(0);
        if ( vecteur.size() == 0) {
            cout << "Utilisation de la méthode norme avec un vecteur vide " << endl;
            return 0;
        } else {
            for( int i(0); i < vecteur.size(); ++i) {
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
            for( int i(0); i < vecteur.size(); ++i) {
                a += vecteur[i] * vecteur[i];
            }
        }
        return a;
    }

