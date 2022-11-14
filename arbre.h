#ifndef PROJETC_TEST_ARBRE_H
#define PROJETC_TEST_ARBRE_H

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// structure de la cellulle
struct noeud;

typedef struct cellule
{
    struct noeud* fils;
    struct cellule* frere;
}cellule;


// cree la structure de la liste des fils dans l'arbre
typedef struct s_std_list
{
    int element;
    struct noeud* liste_noeud ;
} liste_fils;



// cree le noeud de l'arbre
typedef struct noeud
{
    char letter ;
    liste_fils* sons ;
    t_queue* q;
}noeud_arbre;



// cree l'arbre
typedef struct s_tree
{
    noeud_arbre* root;
} arbre_n_aire;





p_cell create_empty_cell();
t_std_list create_empty_list();
p_letter_node create_new_node(char);
int is_letter_in_list(liste_fils, char);
void add_letter_in_list(liste_fils *, char);
void display_list(t_std_list);
void next_letter_node(p_letter_node, char);

#endif //PROJETC_TEST_ARBRE_H
