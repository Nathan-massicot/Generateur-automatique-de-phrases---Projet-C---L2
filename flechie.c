#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "flechie.h"

/* fonction pour créer un type flechie vide
 * retourne un flechie avec ses variables allouées et vides */
t_flechie create_empty_flechie(){
    t_flechie new_flechie;
    new_flechie.mot_flechie = (char *) malloc(MAX_LENGTH);
    new_flechie.code = (char *) malloc(MAX_LENGTH);
    return new_flechie;
}

/* fonction qui permet d'implémenter les valeurs du fichier dans un flechie
 * en paramètre les deux chaines de cractères correspondant au flechie et au code du fichier
 * retourne le flechie implémenté */
t_flechie input_flechie(char * mot_flechie, char * code){
    t_flechie new_flechie = create_empty_flechie();
    new_flechie.mot_flechie = mot_flechie;
    new_flechie.code = code;
    return new_flechie;
}
