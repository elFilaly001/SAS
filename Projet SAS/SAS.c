#include <stdio.h>
#include <stdlib.h>

typedef struct List {
    int Id;
    char title[50], desc[50], date1[50], date2[50],statue[50];
} Lst;

void Ajouter(int a, Lst list[], int *count) {
    int n=1;
    char a1='a realiser';
    char b='en cours de realisation';
    char c='finalisee';


    for (int i = 0; i < a; i++) {
        list[*count].Id=n;
        printf("titre : ");
        scanf("%s", list[*count].title);
        getchar();
        printf("description : ");
        gets(list[*count].desc);
        printf("date de depart: ");
        scanf( "%s", list[*count].date1);
        printf("date de fin: ");
        scanf("%s", list[*count].date2);
        printf("statue: ");
        scanf("%s",list[*count].statue);
        while(list[*count].statue!=a1 || list[*count].statue!=b || list[*count].statue!=c){
            printf("statue: ");
            scanf("%s",list[*count].statue);
        }

        (*count)++;
        n++;
    }
}

void check_statue(Lst list[]){




}

void Aff(int a, Lst list[]) {
    for (int i = 0; i < a; i++) {
        printf("\n------------Task %d:\n", i + 1);
        printf("Id: %d\n", list[i].Id);
        printf("Titre: %s\n", list[i].title);
        printf("Description: %s\n", list[i].desc);
        printf("Date de depart: %s\n", list[i].date1);
        printf("Date de fin: %s\n", list[i].date2);
    }
}

void choix(){
        printf("*********ToDo_List**********\n");
        printf("1-Ajouter une nouvelle tache\n");
        printf("2-Modifier une tache\n");
        printf("3-Supprimer une tache\n");
        printf("4-Afficher vos taches\n");
        printf("5-Rechercher une tache\n");
        printf("6-Statistique\n");
        printf("7-quitter\n\n");
        printf("entrer votre choix : \n");
}

int main() {
    int S, nbr_ln, count = 0;
    Lst list[100];

    do {
        choix();
        scanf("%d", &S);

        switch (S) {
        case 1:
            printf("Combien de tâches voulez-vous ajouter ? ");
            scanf("%d", &nbr_ln);
            Ajouter(nbr_ln, list, &count);
            printf("ajouter avec succe");

        case 4:
            Aff(count, list);

    }
    } while (S!=0);

}
