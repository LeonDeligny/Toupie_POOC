#pragma once
#ifndef TOUPIE_TEXTVIEWER_HPP
#define TOUPIE_TEXTVIEWER_HPP
#include "SupportADessin.hpp"

class TextViewer : public SupportADessin{
public:
    TextViewer(std::ostream& flot)
    :flot(flot) { }

    ~TextViewer() override = default;

    void dessine(Contenu const& a_dessiner) override;

private:
    std::ostream& flot;

};

#endif //TOUPIE_TEXTVIEWER_HPP
