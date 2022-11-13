#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "abre.h"

/* fonction qui permet de créer une cellule vide de type : pointeur sur t_cell : p_cell
 * retourne un p_cell */
p_cell create_empty_cell()
{
    p_cell p_res;
    p_res = (p_cell) malloc(sizeof(t_cell));
    p_res->next = NULL;
    return p_res;
}

/* fonction qui premet de créer une liste vide
 * retourne la liste de vide de type t_std_list */
t_std_list create_empty_list(){
    t_std_list list;
    list.head = NULL;
    return list;
}

/* fonction qui permet de créer une variable vide de type t_letter_node : node vide
 * retourne un pointeur sur t_letter_node : p_letter_node */
p_letter_node create_new_node(char letter){
    p_letter_node new;
    new = (p_letter_node)malloc(sizeof(t_letter_node));
    new->letter = letter;
    new->sons = create_empty_list();
    t_queue q =  create_empty_queue();
    new->q = &q;
    return new;
}

/* fonction qui permet de savoir si une lettre est dans une liste ou non
 * retourne un int : 1 si la lettre est présente, 0 si elle n'est pas */
/** TEMPORAIRE = il faudrait que la liste contienne des adresse vers des noeud, pour l'instant contient des char **/
int is_letter_in_list(t_std_list list, char letter){
    printf("dans la fonction is_letter_in_list\n");
    int res = 0;
    p_cell temp = list.head;
    while (temp!= NULL){
        if (temp->value == letter){
            res = 1;
        }
        temp = temp->next;
    }
    return res;
}

/* fonction qui permet d'ajouter une lettre dans une liste
 * ne retourne rien car modifie seulement la liste en paramètre */
/** à changer car ajoute au début : besoin d'ajouter à la fin **/
void add_letter_in_list(t_std_list * list, char letter){
    p_cell new_cell = create_empty_cell();
    new_cell->value = letter;

    if (list->head == NULL) {
        new_cell->next = NULL;
        list->head = new_cell;
    }else
    {
        p_cell temp = list->head;
        while (temp->next != NULL)
        {
            temp= temp->next;
        }

        temp->next =  new_cell;
        new_cell->next=NULL;
    }
}

/** display **/

void display_list(t_std_list list)
{
    printf(" in ");
    if(list.head == NULL){
        printf("-> out\n");
    }
    else{
        p_cell temp = list.head;
        while(temp != NULL){
            printf("-> | %c |", temp->value);
            temp = temp->next;
        }
        printf("-> out\n");
    }
}



/* fonction qui permet de savoir si la lettre en paramètre est déjà crée dans un noeud de l'arbre */
void next_letter_node(p_letter_node letter_node, char letter) {
    printf("dans la fonction nex_letter_node\n");
    if (is_letter_in_list(letter_node->sons, letter) == 1) {
        printf("dans  le if : OUI letter in sons\n");
    } else {
        printf("dans else : NON letter in sons\n");
        p_letter_node new_letter_node = create_new_node(letter); // créer un nouveau node pour la lettre
        add_letter_in_list(&letter_node->sons, letter); // ajouter la lettre à la liste de lettres : actualiser la liste
        printf("liste :");
        display_list(letter_node->sons);
        printf("\n");
    }
}