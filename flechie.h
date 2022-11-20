
#ifndef LAST_PROJETC_FLECHIE_H
#define LAST_PROJETC_FLECHIE_H
#define MAX_LENGTH 100

typedef struct{
    char * mot_flechie;
    char * mot;
    char * code;
}t_flechie, *p_flechie;

typedef struct s_cell_flechie{
    t_flechie flechie;
    struct s_cell_flechie *next;
}t_cell_flechie, *p_cell_flechie;

typedef struct s_list_flechie{
    p_cell_flechie head;
    int nb_flechie;
}t_list_flechie, *p_list_flechie;

/** fonctions de création des variables */

/* fonction pour créer un type flechie vide
 * retourne un flechie avec ses variables allouées et vides */
t_flechie create_empty_flechie();


/* fonction pour créer une cellule vide de la liste de flechie
 * retourne la cellule crée */
p_cell_flechie create_empty_cell_flechie();

/* fonction qui créer une liste de flechie vide
 * retourne la liste vide */
t_list_flechie create_empty_list();

/** fonctions pour implémenter les structures et arbres */

/* fonction qui permet d'implémenter les valeurs du fichier dans un flechie
 * en paramètre les deux chaines de cractères correspondant au flechie et au code du fichier
 * retourne le flechie implémenté */
t_flechie input_flechie(char *, char *, char *);

/* focntion qui retourne 1 si la liste en paramètre est vide, 0 sinon*/
int is_list_empty(t_list_flechie);

/* ajouter un flechie dans la liste de flechies */
void add_flechie_in_list(t_list_flechie *, char *, char *, char *);

/** différents display utiles  */

/* afficher une liste de flechies */
void display_list_flechies(t_list_flechie);

/* afficher le mot ainsi que ses flechies à partir de sa liste */
void display_flechies(t_list_flechie);

#endif //LAST_PROJETC_FLECHIE_H
