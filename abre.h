#ifndef PROJETC_TEST_ARBRE_H
#define PROJETC_TEST_ARBRE_H

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

// structure de la cellulle

struct s_letter_node;

struct s_cell
{
    char value;
    struct s_cell *next;
    struct s_letter_node *son_next;
};
typedef struct s_cell t_cell, *p_cell;

// cree la structure de la liste des fils dans l'arbre
typedef struct s_std_list
{
    p_cell head;
} t_std_list;

// cree le noeud de l'arbre
struct s_letter_node
{
    char letter ;
    t_std_list sons ;
    t_queue* q;
};
typedef struct s_letter_node t_letter_node, *p_letter_node;


// cree l'arbre
typedef struct s_tree
{
    t_letter_node root;
} t_tree;

p_cell create_empty_cell();
t_std_list create_empty_list();
p_letter_node create_new_node(char);
int is_letter_in_list(t_std_list, char);
void add_letter_in_list(t_std_list *, char);
void display_list(t_std_list);
void next_letter_node(p_letter_node, char);

#endif //PROJETC_TEST_ARBRE_H