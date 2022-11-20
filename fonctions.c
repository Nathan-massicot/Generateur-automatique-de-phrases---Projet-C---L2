#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "arbre.h"

/** Créations des arbres **/

p_letter_node add_node_letter(p_letter_node node, char letter){
    if(last_son(node) == 0){ //le node n'a pas de sons
        p_letter_node new_node = create_new_node(letter);
        node->sons[0] = new_node;
        return new_node;
    }else{
        if (is_letter_in_sons(node,letter) == NULL){ //si la lettre n'est pas déjà dans les sons
            p_letter_node new_node = create_new_node(letter);
            node->sons[0] = new_node;P
            return new_node;

        }else{// la lettre est déjà présente
            return is_letter_in_sons(node,letter);
        }
    }
}


void create_mot_node(p_letter_node node, char * mot, char * mot_flechie, char * code){
    p_letter_node last_node = create_empty_node();
    last_node = node;
    size_t size_mot = strlen(mot);
    for (int i = 0; i<size_mot ; i++){ //parcourir cahque lettre du mot
        last_node = add_node_letter(last_node,mot[i]);
        if (i == size_mot -1){ //implémenter le fléchie sur le dernier node du mot
            add_flechie_in_list(last_node->f, mot_flechie, mot, code);
        }
    }
}


/** fonctions du menu */

void menu_gen_phrases(){
    int sous_menu;
    do{
        /* affichage du sous menu : Générateur de phrases aléatoires */
        printf("\n\tGénérateur de phrases aléatoires\n");
        printf("\t1 . Modèle 1\n"
               "\t2 . Modèle 2\n"
               "\t3 . Autre Modèle\n"
               "\t0 . Retour\n");

        do{
            printf("Entrez le nombre correspondant à l'action choisie :");
            scanf("%d",&sous_menu);
            printf("\n");
        }while((sous_menu < 0)||(sous_menu >= 4 ));

        switch(sous_menu){
            case 1:
                /** Modèle 1 **/
                printf("la fonction n'est pas encore implémentée\n");
                break;
            case 2:
                /** Modèle 2 **/
                printf("la fonction n'est pas encore implémentée\n");
                break;
            case 3:
                /** Modèle 3 **/
                printf("la fonction n'est pas encore implémentée\n");
                break;
            default:
                printf("retour\n");
        }

    }while (sous_menu != 0);
}

void menu_info_dictionnaire(){
    int sous_menu;
    do{
        /* affichage du sous menu : Informations sur le dictionnaire */
        printf("\n\tInformations sur le dictionnaire\n");
        printf("\t1 . Recherche de mot parmi les formes de base\n"
               "\t2 . Extraire une forme de base au hasard\n"
               "\t0 . Retour\n");

        do{
            printf("Entrez le nombre correspondant à l'action choisie :");
            scanf("%d",&sous_menu);
            printf("\n");
        }while((sous_menu < 0)||(sous_menu >= 3 ));

        switch(sous_menu){
            case 1:
                /* Recherche de mot parmi les formes de base */
                printf("la fonction n'est pas encore implémentée\n");
                break;
            case 2:
                /* Extraire une forme de base au hasard */
                printf("la fonction n'est pas encore implémentée\n");
                break;
            default:
                printf("retour\n");
        }

    }while (sous_menu != 0);
}
