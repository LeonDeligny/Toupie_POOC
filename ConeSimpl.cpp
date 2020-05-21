#include "ConeSimple.h"
#include <cmath>
#include "Matrice33.h"
using std::endl;

std::ostream& ConeSimple::affiche(std::ostream& sortie) const{
    /*Cette fonction sert à surcharger l'opérateur d'affichage << comme demandé*/
    sortie << "Cone Simple " << endl;
    Toupie::affiche(sortie);
    sortie << "rayon (m) : " << rayon_ << endl;
    return sortie;
}

Vecteur ConeSimple::f() {
    /*Cette méthode sert à calculer les dérivées secondes des angles de la toupie, qui sont des attributs de cette dernière.
    Nous avons choisi de créer des variables locales afin d'augmenter la lisibilité du code, et avons suivi les formules données
    par le complément mathématique.*/
    double IA1 = masse * (3.0 / 20.0 * rayon_ * rayon_ + 3.0 / 5.0 * hauteur_ * hauteur_);
    double theta = parametres.get_vecteur()[1];
    double psi_point = derivees.get_vecteur()[0];
    double theta_point = derivees.get_vecteur()[1];
    double phi_point = derivees.get_vecteur()[2];
    double theta_derivee_seconde = (1 / IA1) * (masse * g.norme() * centre_de_masse * sin(theta) + psi_point
                                    * sin(theta) * ((IA1 - moment_dinertie3) * psi_point *
                                      cos(theta) - moment_dinertie3 * phi_point));

    Matrice33 IA(masse*(3.0 / 20.0 * rayon_ * rayon_ + 3.0 / 5.0 * hauteur_ * hauteur_), 0, 0 ,
              0, masse * (9.0 / 16.0) * hauteur_ * hauteur_, 0, 0, 0,
              (3.0 / 10.0) * masse * rayon_ * rayon_);
    Vecteur force_poids( { 0 , - masse * g.norme() * sin(theta) , - masse * g.norme() * cos(theta)} );
    Vecteur AG( { 0, 0, centre_de_masse} );
    Vecteur MA(AG ^ force_poids);
    Vecteur w({theta_point, phi_point * sin(theta), psi_point*cos(theta+ phi_point)});
    Vecteur w_point;
    Vecteur biz({0, 0, phi_point});
    w_point = IA.inv() * ( MA - (w - biz)^( IA * w));
    double psi_derivee_seconde(0);
    double phi_derivee_seconde(0);

    if ( std::abs(theta) <= 0.001) {
        psi_derivee_seconde = 0;
        phi_derivee_seconde = w_point.get_vecteur()[2];
        Vecteur v({psi_derivee_seconde, theta_derivee_seconde, phi_derivee_seconde});
        return v;
    } else {
        psi_derivee_seconde = (theta_point / (IA1 * sin(theta))) * ((moment_dinertie3 - 2 * IA1)
                                * psi_point * cos(theta) + moment_dinertie3 * phi_point);
        phi_derivee_seconde = theta_point / (IA1 * sin(theta)) * ((IA1 - (moment_dinertie3 - IA1)
                                * cos(theta) * cos(theta)) * psi_point - moment_dinertie3 * phi_point * cos(theta));
        Vecteur v({psi_derivee_seconde, theta_derivee_seconde, phi_derivee_seconde});
        return v;
    }
}



Vecteur ConeSimple::invariants_du_mouvement() {
    double psi = parametres.get_vecteur()[0];
    double psi_point = derivees.get_vecteur()[0];
    double theta = parametres.get_vecteur()[1];
    double theta_point = derivees.get_vecteur()[1];
    double phi_point = derivees.get_vecteur()[2];
    double dist_OG((3.0/4.0)*hauteur_);
    Vecteur ez({0,0,1.0});
    Vecteur ey({0,1.0,0});
    Vecteur ex({1.0,0,0});
    Matrice33 repereO_repereG( cos(psi), sin(psi), 0.0, -cos(theta)*sin(psi), cos(psi)*cos(theta), sin(theta), sin(theta)*sin(psi), -sin(theta)*cos(psi), cos(theta) );
    Matrice33 I_repereG(moment_dinertie1, moment_dinertie1, moment_dinertie3);
    Matrice33 I_translation_repereG(masse*dist_OG*dist_OG, masse*dist_OG*dist_OG, 0.0);
    Matrice33 IO_repereG = I_repereG + I_translation_repereG;
    Matrice33 IO_repereO = repereO_repereG.transp() * IO_repereG * repereO_repereG;

    Vecteur a_repereO = repereO_repereG.inv() * ez;

    Vecteur omega_repereG({theta_point, psi_point*sin(theta),psi_point*cos(theta)+phi_point });
    Vecteur omega_repereO = repereO_repereG.transp() * omega_repereG;

    Vecteur OG_repereO = (dist_OG * a_repereO);
    Vecteur OG_repereG = (dist_OG * ez );
    Vecteur LO_repereG = IO_repereG*omega_repereG;
    Vecteur LO_repereO = repereO_repereG.transp() * LO_repereG;

    double Energie = ((0.5 * (omega_repereG * LO_repereG)) + masse * (g * OG_repereO));
    double LO_projection_a = ez * LO_repereO;
    double LO_projection_k = ez * LO_repereG;
    double produit_mixte = (ez * ( omega_repereG^LO_repereG));

    Vecteur invariants_du_mouvement({Energie, LO_projection_k, LO_projection_a, produit_mixte});

    // IL FAUDRAIT VERIFIER Y A UN PROBLEME GENERAL
    return invariants_du_mouvement;
}
