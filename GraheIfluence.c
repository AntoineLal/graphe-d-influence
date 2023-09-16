#include "Mabiblio.h"


int main() {
    t_graphe graphe;
    int menu;
    do {
        printf("\n0 pour quitter  1 pour immprimer les sommets 2 pour imprimer le graphe d influence\n3 pour charger graphe 4 pour sauvegarder graphe 5 pour charge automatique\n");
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


t_sommet initSommet(int numero,char *nom)
{
    t_sommet sommet;
    sommet.numero =(int) malloc(sizeof(int ));
    sommet.numero = numero; /// numero du sommet
    sommet.nom = (char*)malloc(sizeof(char) * (strlen(nom) + 1));
    strcpy(sommet.nom,nom);///nom du sommet
    return sommet;
}

t_graphe matriceAdjacence(t_graphe graphe){
    int matriceBuff[taille][taille] = {
            {0, 1, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 1}, // Remplissage matrice
            {0, 0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0},
            {0, 0, 1, 1, 1, 1, 0}
    };
    for (int i = 0; i < graphe.ordre; ++i) {
        for (int j = 0; j < graphe.ordre; ++j) {
            graphe.matrice[i][j]=matriceBuff[i][j];
        }
    }
    for (int i = 0; i < graphe.ordre; ++i) {
        for (int j = 0; j < graphe.ordre; ++j) {
            printf("%d ",graphe.matrice[i][j]);
        }
        printf("\n");
    }
    return graphe;
}
void afficaheInflu(t_graphe graphe)
{
    int compteur;
    for (int i = 0; i < graphe.ordre; i++)
    {
        compteur = 0;
        printf("\n %s ",graphe.sommets[i].nom);
        for (int j = 0; j < graphe.ordre; j++)
        {
            if (graphe.matrice[i][j])
            {
                if (!compteur)
                {
                    printf("influence :");
                }
                printf("%s ",graphe.sommets[j].nom);
                compteur++;
            }
        }
        if (!compteur)
        {
            printf("n'influence personne");
        }

    }
}

t_graphe initGraphe(int ordre,t_graphe graphe,char **tableauNom)
{
graphe.ordre =(int) malloc(sizeof(int ));
graphe.ordre = ordre;
graphe.sommets = malloc(sizeof (t_sommet)*ordre);
graphe.matrice = malloc(sizeof(int )*taille);
for (int i = 0; i < ordre; ++i) {
graphe.sommets[i] = initSommet(i,tableauNom[i]);
}
for (int j = 0; j < taille; j++)
{
graphe.matrice[j] = malloc(sizeof(int )*taille);
}
matriceAdjacence(graphe);
return graphe;
}

void sauvegardeF(t_graphe graphe,char *FILENAME)
{
    FILE *f;

    f = fopen(FILENAME, "w");

    fprintf(f,"%d ",graphe.ordre);

    for (int i = 0; i < graphe.ordre; i++)
    {
        fprintf(f,"%s ",graphe.sommets[i].nom);
        fprintf(f,"%d ",graphe.sommets[i].numero);

    }

    for (int j = 0; j < graphe.ordre; j++)
    {
        fprintf(f,"\n");

        for (int k = 0; k < graphe.ordre; k++)
        {
            fprintf(f,"%d ",graphe.matrice[j][k]);
        }
    }
    fclose(f);
}

t_graphe charge(char *FILENAME,t_graphe graphe)
{

    graphe.ordre =(int ) malloc(sizeof (int));
    FILE *f;
    f = fopen(FILENAME, "r");
    fscanf(f,"%d ",&graphe.ordre);

    graphe.matrice =(int **) malloc(sizeof (int *)*graphe.ordre);

    for (int i = 0; i < graphe.ordre; i++)
    {
        graphe.matrice[i] =(int *) malloc(sizeof (int)*graphe.ordre);
    }

    graphe.sommets = malloc(sizeof (t_sommet)* graphe.ordre);

    char buffer[32];

    for (int i = 0; i < graphe.ordre; i++)
    {
        graphe.sommets[i].numero = (int)malloc(sizeof (int ));
        fscanf(f,"%s ",buffer);
        fscanf(f,"%d ",&graphe.sommets[i].numero);
        graphe.sommets[i].nom = malloc(sizeof (char )* strlen(buffer));
        strcpy(graphe.sommets[i].nom,buffer);

    }


    for (int j = 0; j < graphe.ordre; j++)
    {
        fscanf(f,"\n");

        for (int k = 0; k < graphe.ordre; k++)
        {

            fscanf(f,"%d ",&graphe.matrice[j][k]);
        }
    }
    fclose(f);
    return graphe;
}

void nomFichiercharge(t_graphe *graphe)
{
    char buffer[32];
    printf("quel est le nom du fichier que vous voulez charger ?\n");
    scanf("%s", buffer);
    printf("\ncharge du fichier %s\n",buffer);
    *graphe = charge(buffer,*graphe);
}

void nomFichierSave(t_graphe graphe)
{
    char buffer[32];
    printf("sous quel nom voulez vous sauvegarder votre fichier ? ?\n");
    scanf("%s", buffer);
    printf("\nsauvegarde du fichier %s\n",buffer);
    sauvegardeF(graphe,buffer);
}