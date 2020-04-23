#pragma once
#ifndef TOUPIE_TEXTVIEWER_HPP
#define TOUPIE_TEXTVIEWER_HPP
#include "SupportADessin.hpp"
#include <iostream>

class Contenu;
class Toupie;
class Systeme;
class ConeSimple;
class Dessinable;
//Les include ne permettent pas le fonctionnement de la classe

class TextViewer : public SupportADessin{
public:
    TextViewer(std::ostream& flot)
    :flot(flot) { }

   virtual  ~TextViewer() = default;

    void dessine(Toupie const& a_dessiner) override;
    void dessine(Systeme const& a_dessiner) override;
    void dessine(ConeSimple const& a_dessiner) override;

private:
    std::ostream& flot;

};

#endif //TOUPIE_TEXTVIEWER_HPP
