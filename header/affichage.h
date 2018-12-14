//TODO COM GLOBAL

#ifndef AFFICHAGE_H
#define AFFICHAGE_H
    //Librairies utilisé dans affichage.cpp
    #include <iostream>
    #include <string>
    using namespace std;
    //Prototypes
    void afficherTablier(Case tablier[][TAILLE_TABLIER]);
    void initialiserTablier(Case tablier[][TAILLE_TABLIER]);
    void afficherScore(const unsigned int& billesRestantes, Case tablier[][TAILLE_TABLIER]);


#endif //AFFICHAGE_H
