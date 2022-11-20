#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "fonctions.h"
#include "arbre.h"

int main() {

    /** Implémentation et création des arbres **/

    t_tree t_nom = create_empty_tree();
    p_letter_node p_node1 = create_new_node('1');
    t_nom.root = p_node1;

    t_tree t_verbe = create_empty_tree();
    p_letter_node p_node2 = create_new_node('2');
    t_verbe.root= p_node2;


    t_tree t_adjectif = create_empty_tree();
    p_letter_node p_node3 = create_new_node('3');
    t_adjectif.root= p_node3;

    t_tree t_adverbe = create_empty_tree();
    p_letter_node p_node4 = create_new_node('4');
    t_adverbe.root = p_node4;



    char * string = (char *) malloc(MAX_LENGTH);
    FILE * inputFile;

    inputFile = fopen("mini_dictionnaire_test.txt", "r");
    if(inputFile == NULL){
        printf("erreur, nous ne pouvons pas ouvrir le fichier");
    }

    char * temp_mot_flechie = (char *) malloc(MAX_LENGTH);
    char * temp_mot = (char *) malloc(MAX_LENGTH);
    char * temp_code = (char *) malloc(MAX_LENGTH);


    while ( ! feof( inputFile ) ) {
        fgets(string, MAX_LENGTH, inputFile);

        temp_mot_flechie = strtok(string, "\t");
        temp_mot = strtok(NULL, "\t");
        temp_code = strtok(NULL, "\n");

        char * mot_flechie = (char *) malloc(MAX_LENGTH);
        char * mot = (char *) malloc(MAX_LENGTH);
        char * code = (char *) malloc(MAX_LENGTH);

        strcpy(mot_flechie,temp_mot_flechie);
        strcpy(mot,temp_mot);
        strcpy(code,temp_code);

        int type_tree = type_mot_arbre(code);
        if (type_tree == 1){
            create_mot_node(t_nom.root,mot,mot_flechie,code);
        }else if(type_tree == 2){
            create_mot_node(t_verbe.root,mot, mot_flechie,code);
        }else if(type_tree == 3){
            create_mot_node(t_adjectif.root,mot, mot_flechie,code);
        }else if(type_tree == 4){
            create_mot_node(t_adverbe.root,mot, mot_flechie,code);
        }

    }
    fclose(inputFile);




    /** Menu et fonctions **/

    int choice ;
    do{
        /* affichage du menu */
        printf("\n\tMENU\n");
        printf("\t1 . Générateur de phrases aléatoires\n"
               "\t2 . Informations sur le dictionnaire\n"
               "\t0 . Quitter\n");

        do{
            printf("Entrez le nombre correspondant au sous-menu choisi : ");
            scanf("%d",&choice);
        }while((choice < 0)||(choice >= 4 ));

        switch(choice){
            case 1:
                menu_gen_phrases();
                break;
            case 2:
                menu_info_dictionnaire();
                break;
            default :
                printf("Quitter\n");
        }

    }while(choice!=0);
    return 0;
}
