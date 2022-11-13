cmake_minimum_required(VERSION 3.23)
project(Generateur_automatique_de_phrases___Projet_C___L2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Generateur_automatique_de_phrases___Projet_C___L2
        .idea/.gitignore
        .idea/Generateur-automatique-de-phrases---Projet-C---L2.iml
        .idea/modules.xml
        .idea/vcs.xml
        .idea/workspace.xml
        flechie.c
        flechie.h
        main.c
        queue.c
        queue.h "abre.c" "abre.h" functions_test.c functions_test.h)
