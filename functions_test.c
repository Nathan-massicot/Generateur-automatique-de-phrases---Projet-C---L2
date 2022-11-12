#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "functions_test.h"
#include "arbre.h"

/* fonction qui permet d'insérer un flechie et ses valeurs dans la queue du mot correspondant
 * modifie directement la queue du mot correspondant, utilise alors un pointeur en paramètre pour la queue */
void insert_flechie_queue(t_queue * q, char * mot_flechie, char * code){
    t_flechie new_flechie  = create_empty_flechie();
    new_flechie.mot_flechie = mot_flechie;
    new_flechie.code = code;
    enqueue(q,mot_flechie,code);
}

/* fonction qui permet de lire ligne par ligne le fichier
 * pour chaque ligne récupérer les valeurs du flechie, du mot, du code si la ligne correspond au mot recherché
 * dans ce cas : ajouter le flechie dans la queue du mot (en paramètre) */
void test_recup(t_queue *q, char * mot_base){
    char * string = (char *) malloc(MAX_LENGTH);
    FILE * inputFile;

    inputFile = fopen("mini_dictionnaire_test.txt", "r");
    if(inputFile == NULL){
        printf("erreur, nous ne pouvons pas ouvrir le fichier");
    }

    char * temp_mot_flechie = (char *) malloc(MAX_LENGTH);
    char * temp_mot = (char *) malloc(MAX_LENGTH);
    char * temp_code = (char *) malloc(MAX_LENGTH);


    while ( ! feof( inputFile ) ) {
        fgets(string, MAX_LENGTH, inputFile);

        temp_mot_flechie = strtok(string, "\t");
        temp_mot = strtok(NULL, "\t");
        temp_code = strtok(NULL, "\n");
        printf("[%s,%s,%s]\n", temp_mot_flechie, temp_mot, temp_code);//pour test

        if (strcoll(temp_mot, mot_base) == 0) {
            //printf("\nMOT TROUVÉ\n"); // pour test

            char * mot_flechie = (char *) malloc(MAX_LENGTH);
            char * mot = (char *) malloc(MAX_LENGTH);
            char * code = (char *) malloc(MAX_LENGTH);

            strcpy(mot_flechie,temp_mot_flechie);
            strcpy(mot,temp_mot);
            strcpy(code,temp_code);

            enqueue(q, mot_flechie, code);

            //printf("mot : %s , : flechie : %s\n", temp_mot, temp_mot_flechie); // pour test
        }
    }
    fclose(inputFile);
}


/* fonction qui defini le type du mot est un nom, un verbe, un adjectif, un adverbe
 * retourne : 0 si rien n'a été trouvé(ereur), 1 : nom, 2 : verbe, 3 : adjectif, 4 : adverbe */
int type_mot_arbre(char * code){
    const char * nom = "Nom";
    const char * verbe = "Ver";
    const char * adjectif = "Adj";
    const char * adverbe = "Adv";

    if (strstr(code,nom) != NULL){
        printf("c'est un nom\n"); // pour test
        return 1;
    }else if(strstr(code,verbe) != NULL){
        printf("c'est un verbe\n"); // pour test
        return 2;
    }else if(strstr(code,adjectif) != NULL){
        printf("c'est un adjectif\n");//pour test
        return 3;
    }else if(strstr(code,adverbe) != NULL){
        printf("c'est un adverbe\n");//pour test
        return 4;
    }else{
        return 0;
    }
}

/* fonction qui lit un fichier ligne par ligne et extrait ses informations
 * permet d'essayer des fonctions
 * essaye la fonction type_mot_arbre qui retourne le type du mot de la ligne */
void test_fonctions(){
    char * string = (char *) malloc(MAX_LENGTH);
    FILE * inputFile;

    inputFile = fopen("mini_dictionnaire_test.txt", "r");
    if(inputFile == NULL){
        printf("erreur, nous ne pouvons pas ouvrir le fichier");
    }

    char * temp_mot_flechie = (char *) malloc(MAX_LENGTH);
    char * temp_mot = (char *) malloc(MAX_LENGTH);
    char * temp_code = (char *) malloc(MAX_LENGTH);


    while ( ! feof( inputFile ) ) {
        fgets(string, MAX_LENGTH, inputFile);

        temp_mot_flechie = strtok(string, "\t");
        temp_mot = strtok(NULL, "\t");
        temp_code = strtok(NULL, "\n");
        printf("[%s,%s,%s]\n", temp_mot_flechie, temp_mot, temp_code); //pour test

        int res_code;
        res_code = type_mot_arbre(temp_code);
        printf("type res_code : %d\n", res_code); //pour test
    }
}


/* fonction qui permet de créer un mot de lettres (nodes) à partir d'un mot */
void create_mot_node(p_letter_node node, char * mot){
    size_t size_mot = strlen(mot);
    //p_letter_node temp = node;

    for(int i = 0; i < size_mot; i++ ){
        printf("letter : %c\n", mot[i]);
        next_letter_node(node,mot[i]);
        /** changer la structure du letter_node comme dit précedemment pour pouvoir continuer
         * car on ne peux pas aceder aux nodes suivants etc */
    }

}