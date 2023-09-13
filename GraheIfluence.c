#include "Mabiblio.h"


int main() {
    //definit l'ordre du graphe
    /*int ordre = 7;
    ///alloue memoire tableau noms
    char **tableauNom=NULL;
    tableauNom = (char **)malloc(ordre * sizeof(char *));
    if (tableauNom == NULL) {
        perror("Erreur d'allocation de mémoire");
        return 1;
    }
    for (int i = 0; i < ordre; i++) {
        tableauNom[i] = (char *)malloc(19 * sizeof(char)); // chaque nom peut contenir jusqu'à 20 caractères
        if (tableauNom[i] == NULL) {
            perror("Erreur d'allocation de mémoire pour le nom");
            return 1;
        }
    }
    ///remplit tableau noms
    strcpy(tableauNom[0],"FrancoisS");
    strcpy(tableauNom[1],"FabienneC");
    strcpy(tableauNom[2],"JulienneP");
    strcpy(tableauNom[3],"LouisM");
    strcpy(tableauNom[4],"BoubakerD");
    strcpy(tableauNom[5],"IlhemF");
    strcpy(tableauNom[6],"JPS");

    ///initalise le graphes
    t_graphe graphe;

    graphe = initGraphe(ordre,graphe,tableauNom);
    for (int i = 0; i < graphe.ordre; ++i) {
        printf("le nom du sommet %d est %s\n",graphe.sommets[i].numero,graphe.sommets[i].nom);
    }

    sauvegardeF(graphe,"../test.txt");


    ///libération de l'espace mémoire

    free(graphe.sommets);
    for (int i = 0; i < ordre; i++)
    {
        free(graphe.matrice[i]);
    }
    free(tableauNom);
     */

    t_graphe graphe = charge("../test.txt",graphe);

    printf("l'odre est :%d\n",graphe.ordre);

    for (int i = 0; i < graphe.ordre; ++i) {
        printf("le nom du sommet %d est %s\n",graphe.sommets[i].numero,graphe.sommets[i].nom);
    }


    return 0;
}
