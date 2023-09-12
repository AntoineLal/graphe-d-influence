#include "Graphe D'influence.h"

int test = 0;


int main() {
    srand(time(NULL));
    int ordre;
    char nom[32];
    t_graphe graphe;
    printf("\nsaisissez l'odre ");
    scanf("%d",&ordre);
    fflush(stdin);
    initialisationGraphe(ordre,&graphe);
    //initGrapheRandom(ordre,&graphe);
    printf("test %d\n",test);
    afficherInfluence(graphe);
    printf("\nsaisissez le nom du fichier ou enregistrer les donnees ; ");
    gets(nom);
    return 0;
}

t_sommet initSommet(int numero,char *nom)
{
    t_sommet sommetRetourner;
    sommetRetourner.nom = malloc(strlen(nom) * sizeof(char));
    strcpy(sommetRetourner.nom,nom);
    sommetRetourner.nbrSommet = numero;
    return sommetRetourner;
}

void initGrapheRandom(int ordre,t_graphe *graphe)
{
    graphe->ordre = ordre;
    graphe->matriceAdjacence = malloc(sizeof(int)*ordre*ordre);
    graphe->tabDynSom = malloc(sizeof(t_sommet)*ordre);

    ///initialisation des influances de manieres aléatoires

    for (int i=0;i<graphe->ordre;i++)
    {
        for (int b=0;b<graphe->ordre;b++)
        {
            graphe->matriceAdjacence[i][b] = rand()%2;
        }
    }
    printf("test 1111\n");

    ///initialisation de tous les sommets

    for (int i = 0; i < graphe->ordre; i++)
    {
        //  initSommet(i,());
    }
}



void initialisationGraphe(int ordre,t_graphe *graphe)
{
    graphe->ordre = ordre;
    graphe->matriceAdjacence = malloc(sizeof(int)*ordre*ordre);
    graphe->tabDynSom = malloc(sizeof(t_sommet)*ordre);

    for (int i=0;i<graphe->ordre;i++)
    {

        printf("saisissez le nom de la personne %d\n",i);
        fflush(stdin);
        scanf("%s",graphe->tabDynSom[i].nom);
        //gets(graphe->tabDynSom[i].nom);

        for (int b=0;b<graphe->ordre;b++)
        {
            if (i!=b) {
                printf("test");
                printf("%d influence %d ? (1 pour oui 0 pour non)\n", i, b);
                scanf(" %d", &graphe->matriceAdjacence[i][b]);
                fflush(stdin);

            } else
                graphe->matriceAdjacence[i][b]=0;
        }
        initSommet(i,graphe->tabDynSom[i].nom);
    }

}

void testInfluence(t_graphe graphe,int i,int b){
    if(graphe.matriceAdjacence[i][b]==1)
    {
        printf("\n%s influence %s",graphe.tabDynSom[i].nom,graphe.tabDynSom[b]);
    }
    else{
        printf("\n%s n influence pas %s",graphe.tabDynSom[i].nom,graphe.tabDynSom[b]);
    }
}

void afficherInfluence(t_graphe graphe){
    for (int i=0;i<graphe.ordre;i++)
    {
        for (int b=0;b<graphe.ordre;b++)
        {
            testInfluence(graphe,i,b);
        }
    }
}

void enregistrerTableauDansFichier(t_graphe  graphe, const char *fichierSave) {
    FILE *fichier = fopen(fichierSave, "r"); // Ouvrir le fichier en mode écriture

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // Parcourir le tableau et enregistrer chaque élément dans le fichier
    for (int i = 0; i < graphe.ordre; i++) {
        for (int j = 0; j < graphe.ordre; j++) {
            fprintf(fichier, "%d ", graphe.matriceAdjacence[i][j]);
        }
        fprintf(fichier, "\n"); // Passer à la ligne suivante dans le fichier
    }

    fclose(fichier); // Fermer le fichier
}

void recupererTableauDansFichier(t_graphe  *graphe, const char *fichierSave) {
    FILE *fichier = fopen(fichierSave, "w"); // Ouvrir le fichier en mode écriture

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // Parcourir le tableau et enregistrer chaque élément dans le fichier
    for (int i = 0; i < graphe->ordre; i++) {
        for (int j = 0; j < graphe->ordre; j++) {
            fscanf(fichier, "%d", &graphe->matriceAdjacence[i][j]);
        }
        fprintf(fichier, "\n"); // Passer à la ligne suivante dans le fichier
    }

    fclose(fichier); // Fermer le fichier
}