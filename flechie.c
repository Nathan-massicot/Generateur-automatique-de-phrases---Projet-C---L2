#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "flechie.h"


t_flechie create_empty_flechie(){
    t_flechie new_flechie;
    new_flechie.mot_flechie = (char *) malloc(MAX_LENGTH);
    new_flechie.mot = (char *) malloc(MAX_LENGTH);
    new_flechie.code = (char *) malloc(MAX_LENGTH);
    return new_flechie;
}


p_cell_flechie create_empty_cell_flechie()
{
    p_cell_flechie p_res;
    p_res = (p_cell_flechie) malloc(sizeof(t_cell_flechie));
    p_res->next = NULL;
    return p_res;
}

t_list_flechie create_empty_list()
{
    t_list_flechie f;
    f.head = NULL;
    f.nb_flechie = 0;
    return f;
}


t_flechie input_flechie(char * mot_flechie, char * mot, char * code){
    t_flechie new_flechie = create_empty_flechie();
    new_flechie.mot_flechie = mot_flechie;
    new_flechie.mot = mot;
    new_flechie.code = code;
    return new_flechie;
}


int is_list_empty(t_list_flechie f)
{
    if(f.head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void add_flechie_in_list(t_list_flechie *f, char * flechie, char *mot, char * code){
    p_cell_flechie new_cell = create_empty_cell_flechie();
    new_cell->flechie = input_flechie(flechie,mot,code);

    if (is_list_empty(*f) == 1) {
        new_cell->next = NULL;
        f->head = new_cell;
    }else
    {
        new_cell->next = f->head;
        f->head = new_cell;
    }
    f->nb_flechie++;
}


void display_list_flechies(t_list_flechie f)
{
    p_cell_flechie temp = f.head;
    printf(" %s  : out ", temp->flechie.mot);
    if(f.head == NULL){
        printf("<- in\n");
        printf("liste vide");
    }
    else{
        while(temp != NULL){
            printf("<- | %s |", temp->flechie.mot_flechie);
            temp = temp->next;
        }
        printf("<- in\n");
    }
}

void display_flechies(t_list_flechie f)
{
    printf(" %s  : \n", f.head->flechie.mot);
    if(f.head != NULL){
        p_cell_flechie temp = f.head;
        while(temp != NULL){
            printf("\t%s\n", temp->flechie.mot_flechie);
            temp = temp->next;
        }
    }else{
        printf("pas de formes fléchies\n");
    }
}

