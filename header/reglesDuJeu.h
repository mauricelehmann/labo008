/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : reglesDuJeu.h
 Auteur(s)   : Maurice Lehmann,Mahé Fuentes, Wènes Limem
 Date        : 13.12.2018

 But         : Prototypes des fonctions utilisée pour les déplacments de billes, les calcules des coups possibles et les entrées utilisateur

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/
#ifndef REGLE_DU_JEU_H
#define REGLE_DU_JEU_H

    #include <cstdlib>
    #include <iostream>
    #include <string>
    #include <limits>
    #include <sstream>
    using namespace std;
    //Prototypes
    bool entreeMouvement(string& mouvement,const string& mouvementsPossibles);
    void deplacerBille(const string& mouvement, Case tablier[][TAILLE_TABLIER]);
    void calculerMouvementsPossibles(string& mouvementsPossibles, Case tablier[][TAILLE_TABLIER]);

#endif //REGLE_DU_JEU_H
