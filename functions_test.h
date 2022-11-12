
#ifndef PROJETC_TEST_FUNCTIONS_TEST_H
#define PROJETC_TEST_FUNCTIONS_TEST_H

#include "queue.h"
#include "arbre.h"

void insert_flechie_queue(t_queue * q, char * mot_flechie, char * code);
void test_recup(t_queue *, char *);
int type_mot_arbre(char *);
void test_fonctions();
void create_mot_node(p_letter_node, char *);

#endif //PROJETC_TEST_FUNCTIONS_TEST_H
