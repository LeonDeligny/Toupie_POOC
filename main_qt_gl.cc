#include <QApplication>
#include "glwidget.h"
#include <cmath>
#include "ConeSimple.hpp"
#include "IntegrateurRungeKutta.hpp"
#include <vector>
#include "Vecteur.hpp"
#include "Systeme.hpp"
#include "ToupieChinoise.hpp"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  IntegrateurRungeKutta New;
  GLWidget w(&New);

  SupportADessin* supp(nullptr);

  Vecteur parametre({0.0, M_PI/8, 0.0});
  Vecteur derivee({0.0, 0.0, 30.0});
  Vecteur position({0.0, 0.0, 0.0});
  Memoire memoire(supp);
  Vecteur v({-2.0, 2.0, 0.0});
  Vecteur v2({2.0, 2.0, 0.0});
  Vecteur parametrechine({0.0, M_PI/8, 0.0, 0.0, 0.0});
  Vecteur parametregenerale({0.0, M_PI/8, 0.0, 2.0, 2.0});
  Vecteur deriveegenerale({0.0, 0.0, 60.0, 0.0, 0.0});
  Vecteur derivechine1({2.0, 0.0, 2.0, -2.0, 2.0});


  ConeSimple test3(position, parametre, derivee, 0.1, 1.5, 1.0, supp, memoire);

  std::vector<double> rayon;
  for(double i(0.01); i<=1; i+=0.01){
      rayon.push_back(i);
  }

  Toupie_Generale test1(v2, parametregenerale, deriveegenerale, 1.5, 0.1, supp, rayon, memoire);


  ToupieChinoise test2(v, parametrechine, derivechine1, 0.4, 0.1, 1.0, supp, memoire);

  w.ajouter_toupie(test2);
  w.ajouter_toupie(test1);
  w.ajouter_toupie(test3);


  w.show();

  delete supp;

  return a.exec();
}
