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
