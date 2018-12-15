/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : constantes.h
 Auteur(s)   : Maurice Lehmann,Mahé Fuentes, Wènes Limem
 Date        : 13.12.2018

 But         : Contient toutes les constantes globales utilisée dans le programmes

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#ifndef CONSTANTES_H
#define CONSTANTES_H

    #include <cstdlib>
    using namespace std;

    const unsigned int NB_BILLES = 32;
    const size_t TAILLE_TABLIER = 7;
    enum class Case { nonValide, plein, vide };

#endif
