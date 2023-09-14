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
    t_graphe graphe;
    int menu;
    do {
        printf("\n0 pour quitter  1 pour immprimer les sommets 2 pour imprimer le graphe d influence\n 3 pour charger graphe 4 pour sauvegarder graphe 5 pour charge automatique\n");
        scanf("%d",&menu);
        if (menu == 1){
            printf("l'odre est :%d\n",graphe.ordre);

            for (int i = 0; i < graphe.ordre; ++i) {
                printf("le nom du sommet %d est %s\n",graphe.sommets[i].numero,graphe.sommets[i].nom);
            }
        }
        if(menu==2){afficaheInflu(graphe);}
        if(menu==3){nomFichiercharge(&graphe);}
        if(menu==4){ nomFichierSave(graphe);}
        if(menu==5){graphe = charge("../test.txt",graphe);}
    } while (menu !=0);








    return 0;
}
