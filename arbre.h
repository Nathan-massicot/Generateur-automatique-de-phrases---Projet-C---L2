//
// Created by Clarisse Aubert on 20/11/2022.
//

#ifndef LAST_PROJETC_ARBRE_H
#define LAST_PROJETC_ARBRE_H
#include "flechie.h"

typedef struct s_letter_node
{
    char letter;
    struct s_letter_node * sons[26];
    t_list_flechie * f;

}t_letter_node, *p_letter_node;

typedef struct s_tree
{
    p_letter_node root;
} t_tree;

/** fonction pour créer des variables à partir des structures du arbre.h **/

/* fonction qui affiche chaque noeud */
void display_node(p_letter_node);

/* focntion qui permet de créer un p_letter_node vide et alloue de la mémoire*/
p_letter_node create_empty_node();

/* fonction qui permet de créer une variable vide de type t_letter_node : node vide
 * retourne un pointeur sur t_letter_node : p_letter_node */
p_letter_node create_new_node(char);

/* fonction qui permet de créer un arbre vide
 * retourne le t_tree vide */
t_tree create_empty_tree();

/* fonction qui permet de savoir si une lettre est dans les sons du node en paramètres ou non
 * retourne un pointeur sur le node qui contient la lettre recherchée si elle est trouvée
 * retourne NULL si la lettre n'a pas été trouvée */
p_letter_node is_letter_in_sons(p_letter_node, char);

/* fonction qui permet de retourner l'emplacement du dernier node des sons */
int last_son(p_letter_node);

/** fonctions utiles à l'implémentation des arbres et modèles */

/* fonctions qui definissent le type, genre, temps, nombre, personne d'un mot
 * retourne 0 si rien n'a été trouvé */

/* 1 : nom, 2 : verbe, 3 : adjectif, 4 : adverbe */
int type_mot_arbre(char *);
/* 1 : masculin, 2 : feminin */
int genre_mot_arbre(char *);
/* 1 : Infinitif, 2 : présent de l'indicatif, 3 : imparfait de l'indicatif, 4 : présent du subjonctif */
int temps_mot_arbre(char *);
/* 1 : pluriel, 2 : singulier */
int nombre_mot_arbre(char *);


#endif //LAST_PROJETC_ARBRE_H
