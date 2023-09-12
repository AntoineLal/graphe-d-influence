//
// Created by antoi on 11/09/2023.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include "time.h"


#ifndef THEORIEGRAPHE_MABIBLIO_H
#define THEORIEGRAPHE_MABIBLIO_H

#endif //THEORIEGRAPHE_MABIBLIO_H


typedef struct sommet{
    char *nom;
    int nbrSommet;
}t_sommet;

typedef struct graphe{
    int **matriceAdjacence;
    int ordre;
    t_sommet* tabDynSom;
}t_graphe;
t_sommet initSommet(int numero,char *nom);

void  initialisationGraphe(int ordre,t_graphe *graphe);

void initGrapheRandom(int ordre,t_graphe *graphe);

void afficherInfluence(t_graphe graphe);