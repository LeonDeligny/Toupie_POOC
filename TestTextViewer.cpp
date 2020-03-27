#include <iostream>
#include "TextViewer.hpp"
#include "Dessinable.hpp"
using namespace std;

int main(){
    TextViewer ecran(cout);

    Contenu c(&ecran);

    c.dessine();

}


