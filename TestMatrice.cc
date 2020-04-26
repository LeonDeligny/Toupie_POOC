#include "Matrice33.h"
#include <iostream>
#include "Vecteur.h"
using std::cout;
using std::endl;

int main(){

    Matrice33 mat1(1, 2, 3, 4, 5, 6, 7, 8, 2);
    Matrice33 id;
    Matrice33 diag(3, 8, -2.3);
    cout<<"transpo 1"<<mat1.transp()<<endl;
    cout<<" diag det"<<diag.det()<<endl;
    cout<<"diag inv"<<mat1.inv();
    Vecteur v1({2, 7.3, 9});
    cout<<"matrice fois vecteur"<<mat1*v1<<endl;
    cout<<"addition "<<mat1+diag<<endl;
    cout<<"soustration "<<diag-mat1<<endl;
    cout<<"multiplication "<<mat1*mat1<<endl;


    return 0;
}

