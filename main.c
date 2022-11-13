
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions_test.h"

int main(){
    char * mot_base = "stabiliser";
    t_queue q_mot = create_empty_queue();

    printf("\n\nTEST 1 : File de fléchie d'un mot\n\n");
    test_recup(&q_mot, mot_base);
    printf("file de %s : ", mot_base);
    displayQueue(q_mot);
    printf("\n");
    printf("nombre de formes flechies : %d", q_mot.nb_flechie);

    printf("\n\nTEST 2 : types des mots\n\n");
    test_fonctions();


    /** ne fonctionne pas réellement car il faut changer la structure du node : letter_node pour continuer un bon truc*/
    printf("\n\nTEST 3  : types des mots\n\n");
    t_tree tree;
    char * mot = "stabiliser";
    create_mot_node(&tree.root,mot);

    return 0;
}
