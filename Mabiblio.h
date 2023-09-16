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



//
// Created by eudess on 13/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 7

typedef struct sommet{
    char *nom;
    int numero;
}t_sommet;
typedef struct graphe{
    int ordre;          /// L'ordre
    int **matrice;      /// La matrice d'adjacence dynamique d'entiers
    t_sommet *sommets;  /// Un tableau dynamique de sommets
}t_graphe;
t_sommet initSommet(int numero,char *nom);


t_graphe matriceAdjacence(t_graphe graphe);
void afficaheInflu(t_graphe graphe);

t_graphe initGraphe(int ordre,t_graphe graphe,char **tableauNom);

void sauvegardeF(t_graphe graphe,char *FILENAME);

t_graphe charge(char *FILENAME,t_graphe graphe);

void nomFichiercharge(t_graphe *graphe);
void nomFichierSave(t_graphe graphe);