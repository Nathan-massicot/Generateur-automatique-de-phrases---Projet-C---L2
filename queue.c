#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

p_cell_flechie create_empty_cell_flechie()
{
    p_cell_flechie p_res;
    p_res = (p_cell_flechie) malloc(sizeof(t_cell_flechie));
    p_res->next = NULL;
    return p_res;
}

t_queue create_empty_queue()
{
    t_queue q;
    q.head = NULL;
    q.first = q.last = 0;
    q.nb_flechie = 0;
    return q;
}

int isQueueEmpty(t_queue q)
{
    return (q.first == q.last);
}

int isQueueFull(t_queue q)
{
    return (q.last-q.first == MAX);
}

void enqueue(t_queue *pq, char * flechie, char * code){
    p_cell_flechie new_cell = create_empty_cell_flechie();
    new_cell->flechie = input_flechie(flechie,code);

    if (isQueueEmpty(*pq) == 1) {
        new_cell->next = NULL;
        pq->head = new_cell;
    }else
    {
        new_cell->next = pq->head;
        pq->head = new_cell;
    }

    pq->nb_flechie++;
    pq->last = pq->last+1;
}

void displayQueue(t_queue q)
{
    printf(" out ");
    if(q.head == NULL){
        printf("<- in\n");
    }
    else{
        p_cell_flechie temp = q.head;
        while(temp != NULL){
            printf("<- | %s |", temp->flechie.mot_flechie);
            temp = temp->next;
        }
        printf("<- in\n");
    }
}

