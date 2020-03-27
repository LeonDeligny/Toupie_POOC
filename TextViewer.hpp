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

class TextViewer : public SupportADessin{
public:
    TextViewer(std::ostream& flot)
    :flot(flot) { }

   virtual  ~TextViewer() { }

    void dessine(Contenu const& a_dessiner) override;
    void dessine(Toupie const& a_dessiner) override;
    void dessine(Systeme const& a_dessiner) override;
    void dessine(ConeSimple const& a_dessiner) override;

private:
    std::ostream& flot;

};

#endif //TOUPIE_TEXTVIEWER_HPP
