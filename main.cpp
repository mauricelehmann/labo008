//Custom files
#include "header/constantes.h"
#include "header/affichage.h"
#include "header/reglesDuJeu.h"

using namespace std;

int main(){

    //On initialise le tablier comme un tableau de 7x7 éléments
    Case tablier[TAILLE_TABLIER][TAILLE_TABLIER] ;
    //unsigned int billesRestantes = NB_BILLES;
    bool continuer = true;
    string mouvement;

    initialiserTablier(tablier,TAILLE_TABLIER);

    do{
        afficherTablier(tablier,TAILLE_TABLIER);
        //Tant que le mouvement entré n'est pas valide, on redemande et on affiche le tableau
        while(!entreeMouvement(mouvement)){
            afficherTablier(tablier,TAILLE_TABLIER);
        }

    }while(continuer);


    return EXIT_SUCCESS;
}
