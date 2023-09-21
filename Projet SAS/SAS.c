#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <time.h>

typedef struct List {
    int Id,statue;
    char title[50], desc[50];
    struct tm deadline;
} Lst;

void Ajouter(int a, Lst list[], int *count) {
    int n= *count +1;

    for (int i = 0; i < a; i++) {
        list[*count].Id=n;
        printf("titre : ");
        scanf("%s", list[*count].title);
        getchar();
        printf("description : ");
        gets(list[*count].desc);
        printf("deadline : ");
        scanf( "%d/%d/%d", &list[*count].deadline.tm_mday,&list[*count].deadline.tm_mon,&list[*count].deadline.tm_year);
        printf("statue : ");
        printf("1- a realiser\t 2-en cours\t 3-finalisee\n");
        scanf("%d",&list[*count].statue);

        while(list[*count].statue >3 || list[*count].statue<1){
            printf("statue : ");
            printf("1- a realiser\t 2-en cours\t 3-finalisee\n");
            scanf("%d",&list[*count].statue);
        }

        (*count)++;
        n++;
    }
}

void Aff(int a, Lst list[]) {
    for (int i = 0; i < a; i++) {
        printf("\n------------Task %d:\n", i + 1);
        printf("Id: %d\n", list[i].Id);
        printf("Titre: %s\n", list[i].title);
        printf("Description: %s\n", list[i].desc);
        printf("Date de depart: %d/%d/%d\n",list[i].deadline.tm_mday,list[i].deadline.tm_mon,list[i].deadline.tm_year);
        if (list[i].statue==1){
            printf("statue : a realiser\n");
        }else if (list[i].statue==2){
            printf("statue : en cours de realisation\n");
        }else if (list[i].statue==3){
            printf("statue : finalisee\n");
        }
    }
}

void choix(){
        printf("\n*********ToDo_List**********\n");
        printf("1-Ajouter une nouvelle tache\n");
        printf("2-Modifier une tache\n");
        printf("3-Supprimer une tache\n");
        printf("4-Afficher vos taches\n");
        printf("5-Rechercher une tache\n");
        printf("6-Statistique\n");
        printf("7-quitter\n\n");
        printf("entrer votre choix : \n");
}


void modifier(int index ,int a, Lst list[]){

    int ch,d,m,y;
    char tr[100] , des[100] , space[100];


    printf("1-modifier le titre \t2-modifier la description\t3-modifer deadline\n");
    scanf("%d",&ch);
    while (ch < 1 || ch > 3){
        printf("Choix invalide. Veuillez entrer 1, 2 ou 3 : \n");
        scanf("%d",&ch);
    }
    if(ch==1){
        printf("entrer le nouveaux titre\n");
        scanf("%s", tr);
        strcpy(list[index-1].title,tr);
    }else if(ch==2){
        printf("entrer le nouvelle description\n");
        scanf("%s",des);
        strcpy(list[index-1].desc,des);
    }else if (ch==3){
        printf("entrer le nouvelle deadline\n");
        scanf("%d/%d/%d",&d,&m,&y);
        list[index-1].deadline.tm_mday=d;
        list[index-1].deadline.tm_mon=m;
        list[index-1].deadline.tm_year=y;
    }


}


void sup(int index , int a , Lst list[]){
    int lng = sizeof(list) / sizeof(list[0]);


    for (int i = index ; i < lng ; i++)
     {
         list[i] = list[i+1];
     }
}
int main() {
    int S, nbr_ln, count = 0,index;
    Lst list[100];

    do {
        choix();
        scanf("%d", &S);

        switch (S) {
        case 1:
            printf("Combien de tâches voulez-vous ajouter ? \n");
            scanf("%d", &nbr_ln);
            Ajouter(nbr_ln, list, &count);
            printf("ajouter avec succee");
            break;
        case 2 :
            for (int i=0 ; i<count ; i++){
                printf("\n----------------------------------\n");
                printf("Id: %d\n", list[i].Id);
                printf("Titre: %s\n", list[i].title);
            }
            printf("entrer l'index que vous voulez modifier \n");
            scanf("%d", &index);
            modifier(index,count,list);
            break;
        case 3 :
            for (int i=0 ; i<count ; i++){
                printf("\n----------------------------------\n");
                printf("Id: %d\n", list[i].Id);
                printf("Titre: %s\n", list[i].title);
            }
            printf("entrer l'index que vous voulez modifier \n");
            scanf("%d", &index);
            sup(index,count,list);

        case 4:
            if(count<=0){
                printf("rien a afficher veiller ajouter une tache");
            }else{
                Aff(count, list);
            }

            break;
    }
    } while (S!=0);

}
