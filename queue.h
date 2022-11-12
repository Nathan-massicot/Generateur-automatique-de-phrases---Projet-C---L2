#ifndef PROJETC_TEST_QUEUE_H
#define PROJETC_TEST_QUEUE_H

#define MAX 10

#include "flechie.h"

struct s_cell_flechie{
    t_flechie flechie;
    struct s_cell_flechie *next;
};
typedef struct s_cell_flechie t_cell_flechie, *p_cell_flechie;

struct s_queue{
    p_cell_flechie head;
    int first, last;
    int nb_flechie;
};
typedef struct s_queue t_queue, *p_queue;



p_cell_flechie create_empty_cell_flechie();
t_queue create_empty_queue();
int isQueueEmpty(t_queue);
int isQueueFull(t_queue);
void enqueue(t_queue *, char *, char *);
void displayQueue(t_queue );

#endif //PROJETC_TEST_QUEUE_H
