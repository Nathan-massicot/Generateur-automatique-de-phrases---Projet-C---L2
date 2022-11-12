#ifndef PROJETC_TEST_FLECHIE_H
#define PROJETC_TEST_FLECHIE_H

#define MAX_LENGTH 80

struct s_flechie{
    char * mot_flechie;
    char * code;
};
typedef struct s_flechie t_flechie, *p_flechie;

t_flechie create_empty_flechie();
t_flechie input_flechie(char * , char * );

#endif //PROJETC_TEST_FLECHIE_H
