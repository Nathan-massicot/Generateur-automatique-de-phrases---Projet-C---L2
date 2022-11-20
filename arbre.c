#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "arbre.h"

void display_node(p_letter_node node){
    if (node != NULL){
        printf("lettre %c\n", node->letter);
        for(int i = 0; i< last_son(node); i++){
            printf("son %d : lettre %c\n", i, node->sons[i]->letter);
        }
    }
}

p_letter_node create_empty_node(){
    p_letter_node new;
    new = (p_letter_node) malloc(sizeof(t_letter_node));
    for (int i = 0; i < 26; i++){
        new->sons[i] = malloc(sizeof(t_letter_node));
        new->sons[i]->letter = '0';
    }
    t_list_flechie f = create_empty_list();
    new->f = &f;
    return new;
}

p_letter_node create_new_node(char letter) {
    p_letter_node new;
    new = (p_letter_node) malloc(sizeof(t_letter_node));
    new->letter = letter;
    for (int i = 0; i < 26; i++){
        new->sons[i] = malloc(sizeof(t_letter_node));
        new->sons[i]->letter = '0';
    }
    t_list_flechie f = create_empty_list();
    new->f = &f;
    return new;
}

t_tree create_empty_tree(){

    t_tree tree;

    tree.root = NULL;

    return tree;
}


p_letter_node is_letter_in_sons(p_letter_node node, char letter){
    p_letter_node temp = create_empty_node();
    for (int i = 0; i< last_son(node); i++){
        if (node->sons[i]->letter == letter){
            temp = node->sons[i];
        }else{
            temp = NULL;
        }
    }
    return temp;
}

int last_son(p_letter_node node){
    for(int i = 0; i < 26; i++){
        if (node->sons[i]->letter == '0'){
            return i;
        }
    }
    return 0;
}

/** fonctions utiles à l'implémentation des arbres et modèles */

int type_mot_arbre(char * code){
    const char * nom = "Nom";
    const char * verbe = "Ver";
    const char * adjectif = "Adj";
    const char * adverbe = "Adv";

    if (strstr(code,nom) != NULL){
        return 1;
    }else if(strstr(code,verbe) != NULL){
        return 2;
    }else if(strstr(code,adjectif) != NULL){
        return 3;
    }else if(strstr(code,adverbe) != NULL){
        return 4;
    }else{
        return 0;
    }
}

int genre_mot_arbre(char * code){
    const char * masculin = "Mas";
    const char * feminin = "Fem";
    const char * invariable = "InvGen";

    if (strstr(code,masculin) != NULL){
        return 1;
    }else if(strstr(code,feminin) != NULL){
        return 2;
    }else if(strstr(code,invariable) != NULL){
        return 3;
    }else{
        return 0;
    }
}

int temps_mot_arbre(char * code){
    const char * infinitif = "Inf";
    const char * pres_ind = "IPre";
    const char * imp_ind = "IImp";
    const char * pres_subj = "SPre";

    if (strstr(code, infinitif) != NULL){
        return 1;
    }else if(strstr(code,pres_ind) != NULL){
        return 2;
    }else if(strstr(code,imp_ind) != NULL){
        return 3;
    }else if(strstr(code,pres_subj) != NULL){
        return 4;
    }else{
        return 0;
    }
}


int nombre_mot_arbre(char * code){
    const char * pluriel = "PL";
    const char * singulier = "SG";

    if (strstr(code,pluriel) != NULL){
        return 1;
    }else if(strstr(code,singulier) != NULL){
        return 2;
    }else{
        return 0;
    }
}






