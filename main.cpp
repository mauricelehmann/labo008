/*
 -----------------------------------------------------------------------------------
 Laboratoire : 08
 Fichier     : main.cpp
 Auteur(s)   : Maurice Lehmann,Mahé Fuentes, Wènes Limem
 Date        : 13.12.2018

 But         :Simule un jeu de solitaire, dans sa version 32 billes
              L'utilisateur est invité à rentrer des commandes correspondant aux déplacement des billes
              sur le tablier.
              Il peut également demander de l'aide qui lui donnera la liste des mouvements possibles

 Remarques   : L'algorithm principal fonctionne de la manière suivante :
               On initialise le tablier (tableau 7x7) avec 3 valeurs possibles : vide, plein ou non-valide (hors tablier)
               On calcule tous les mouvements possibles par rapport au tablier
               L'utilisateur entre un mouvement, si ce mouvement fait parti des mouvements possibles on l'accepte
               On applique le mouvements au tablier et on recommence 

 Compilateur : MinGW-g++
 -----------------------------------------------------------------------------------
*/

#include "header/constantes.h"
#include "header/affichage.h"
#include "header/reglesDuJeu.h"

using namespace std;

int main(){


    //TIPS: Pour tester si on arrive a faire une partie du début à la fin, on peut copier coller cette suite de mouvements :
    //64u 52r 73u 43d 75l 73u 45l 43d 32d 51r 31d 54l 51r 63u 65u 57l 45d 37d 36d 57l 65u 34r 15d 13r 45u 15d 36l 24d 44l 23d 42r

    //On initialise le tablier comme un tableau de 7x7 éléments
    Case tablier[TAILLE_TABLIER][TAILLE_TABLIER] ;
    unsigned int billesRestantes;
    bool continuer = true;
    string mouvement, mouvementsPossibles;

    initialiserTablier(tablier);
    billesRestantes = NB_BILLES;

    do{
        afficherTablier(tablier);
        //On calcule les mouvements possibles
        calculerMouvementsPossibles(mouvementsPossibles,tablier);
        //Tant que le mouvement entré n'est pas valide, on redemande et on affiche le tableau
        while(!entreeMouvement(mouvement,mouvementsPossibles)){
            //On affiche le tablier
            afficherTablier(tablier);
            if(mouvement == "q"){
                //L'utlisateur veut arreter sa partie :
                //Fonction qui affiche le score / qui demande de recommencé ?
                afficherScore(billesRestantes, tablier);
                //On arrête cette partie
                continuer = false;
                break;
            }
            if(mouvement == "h"){
                //L'utilisateur veut de l'aide :
                afficherMouvementsPossibles(mouvementsPossibles);
                //Fonction qui affiche le score / qui demande de recommencé ?
            }
            //Check si le mouvement est deja dans la liste des mouvement permis

        }
        //On applique le mouvment entree sur le tablier:
        deplacerBille(mouvement,tablier);
        billesRestantes--;
        //Important : le mouvement entré est deja validé par entreeMouvement() !
        //On reset les mouvements possibles
        mouvementsPossibles = "";

        if(billesRestantes == 1){
            //Le joueur a finit la partie
            afficherTablier(tablier);
            afficherScore(billesRestantes, tablier);
            continuer = false;
        }
    }while(continuer);

    return EXIT_SUCCESS;
}
