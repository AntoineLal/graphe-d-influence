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
// Created by eudes on 13/09/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define taille 2

typedef struct sommet{
    char *nom;
    int numero;
}t_sommet;
t_sommet initSommet(int numero,char *nom)
{
    t_sommet sommet;
    sommet.numero =(int) malloc(sizeof(int ));
    sommet.numero = numero; /// numero du sommet
    sommet.nom = (char*)malloc(sizeof(char) * (strlen(nom) + 1));
    strcpy(sommet.nom,nom);///nom du sommet
    return sommet;
}
typedef struct graphe{
    int ordre;          /// L'ordre
    int **matrice;      /// La matrice d'adjacence dynamique d'entiers
    t_sommet *sommets;  /// Un tableau dynamique de sommets
}t_graphe;
t_graphe initGraphe(int ordre,t_graphe graphe,char **tableauNom)
{
    graphe.ordre =(int) malloc(sizeof(int ));
    graphe.ordre = ordre;
    graphe.sommets = malloc(sizeof (t_sommet)*ordre);
    for (int i = 0; i < ordre; ++i) {
        graphe.sommets[i] = initSommet(i,tableauNom[i]);
    }
    return graphe;
}