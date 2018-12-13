#include "header/constantes.h"
#include "header/reglesDuJeu.h"

bool entreeMouvement(string& mouvement){

    char direction;
    unsigned int position;
    bool entreeValide = true;

    do{
        cout << "Entrez un mouvement a effectuer : (numero de la case + 'u','d','r','l') :";
        cin >> position >> direction ;
        if(cin.fail()){
            //On vide le buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Mouvement non-valide!" << endl;
            return false;
        }else{
            entreeValide = false;
        }
    }while(entreeValide);

    //On regarde si la postion n'est pas hors bornes valides
    if(!(
        ((position > 12) && (position < 16)) ||
        ((position > 22) && (position < 26)) ||
        ((position > 30) && (position < 58)) ||
        ((position > 62) && (position < 66)) ||
        ((position > 72) && (position < 76))
    ))
    {
        cout << "position non-valide!"<<endl;
        return false;
    }
    //On check si la direction est correct
    if(direction != 'u' && direction != 'd' && direction != 'l' && direction != 'r'){
        cout <<"Direction non valide!"<<endl;
        return false;
    }

    return true;

}
