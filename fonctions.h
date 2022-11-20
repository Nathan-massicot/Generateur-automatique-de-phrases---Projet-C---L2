
#ifndef LAST_PROJETC_FONCTIONS_H
#define LAST_PROJETC_FONCTIONS_H
#include "arbre.h"

/** fonctions utiles à l'implémentation des arbres et modèles */

/* fonction qui permet d'ajouter une lettre si elle n'est pas déjà présente dans les sons
 * retourne un pointeur sur le noeud contenant la lettre */
p_letter_node add_node_letter(p_letter_node, char);

/* fonction qui permet de créer un mot lettre par lettre ainsi que d'ajouter au node de la dernière lettre ses fléchies
 * retourne un pointeur sur le dernier node */
void create_mot_node(p_letter_node, char *, char *, char *);

/** fonctions du menu */
void menu_gen_phrases();
void menu_info_dictionnaire();
void menu_fonctions_actu();

#endif //LAST_PROJETC_FONCTIONS_H
