//Custom files
#include "header/constantes.h"
#include "header/affichage.h"
#include "header/reglesDuJeu.h"

using namespace std;

int main(){

    //On initialise le tablier comme un tableau de 7x7 éléments
    Case tablier[TAILLE_TABLIER][TAILLE_TABLIER] ;
    unsigned int billesRestantes;
    bool continuer = true;
    string mouvement;

    initialiserTablier(tablier);
    billesRestantes = NB_BILLES;

    do{
        afficherTablier(tablier);
        //Tant que le mouvement entré n'est pas valide, on redemande et on affiche le tableau
        while(!entreeMouvement(mouvement)){
            afficherTablier(tablier);
            if(mouvement == "q"){
                //L'utlisateur veut arreter sa partie :
                //Fonction qui affiche le score / qui demande de recommencé ?
                afficherScore(billesRestantes, tablier);
                //On arrête cette partie
                continuer = false;
            }
            if(mouvement == "h"){
                //L'utilisateur veut de l'aide :
                //Fonction qui affiche le score / qui demande de recommencé ?
            }
            //On applique le mouvment entree sur le tablier:
            //TODO -> Fonction qui modifie le tablier d'apres un mouvement donné
            //Important : le mouvement entré est deja validé par entreeMouvement() !

            if(billesRestantes == 1){
                //Le joueur a finit la partie
                afficherScore(billesRestantes, tablier);
                continuer = false;
            }
            //TODO -> checker avec la fonction qui trouve les mouvement possible, si il y en a encore.
            //si il y en a plus, on arrete la partie et on affiche le score
        }
    }while(continuer);

    return EXIT_SUCCESS;
}
