#include <dos.h>
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
        printf("-------------------TASK%d\n",i+1);
        printf("titre : ");
        scanf("%s", list[*count].title);
        getchar();
        printf("description : ");
        gets(list[*count].desc);

        do {
    printf("deadline (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &list[*count].deadline.tm_mday, &list[*count].deadline.tm_mon, &list[*count].deadline.tm_year);
} while (
    (list[*count].deadline.tm_mday < 1 || list[*count].deadline.tm_mday > 31) ||
    (list[*count].deadline.tm_mon < 1 || list[*count].deadline.tm_mon > 12) ||
    (list[*count].deadline.tm_year < 2000));
        do {
            printf("statue : ");
            printf("1- a realiser\t 2-en cours\t 3-finalisee\n");
            scanf("%d",&list[*count].statue);
        }while(list[*count].statue >3 || list[*count].statue<1);


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

    int st,ch,d,m,y;
    char des[100];


    printf("1-modifier statue\t2-modifier la description\t3-modifer deadline\n");
    scanf("%d",&ch);
    while (ch < 1 || ch > 3){
        printf("Choix invalide. Veuillez entrer 1, 2 ou 3 : \n");
        scanf("%d",&ch);
    }
    if(ch==1){
        printf("entrer la nouvelle statue\n\n");
        printf("1- a realiser\t 2-en cours\t 3-finalisee\n");
        scanf("%d",&st);

        while(st >3 || st<1){
            printf("statue : ");
            printf("1- a realiser\t 2-en cours\t 3-finalisee\n");
            scanf("%d",&st);
        }
        list[index-1].statue=st;
    }else if(ch==2){
        printf("entrer le nouvelle description\n");
        scanf("%s",des);
        strcpy(list[index-1].desc,des);
    }else if (ch==3){
        do {
        printf("Enter the new deadline (dd/mm/yyyy): ");
        scanf("%d/%d/%d", &d, &m, &y);
    } while (
        (d < 1 || d > 31) ||
        (m < 1 || m > 12) ||
        (y < 2000)
    );

        list[index-1].deadline.tm_mday=d;
        list[index-1].deadline.tm_mon=m;
        list[index-1].deadline.tm_year=y;
    }


}


void sup(int index , Lst list[],int lng, int *count){

    for (int i = index -1; i < index ; i++){
        list[i] = list[i + 1];
    }
  (*count)--;
}


void rechID(int rech, Lst list[], int lng)
{
    for (int i = 0; i < lng; i++)
    {
        if (rech == list[i].Id)
        {
            printf("---------------------TASK%d\n",i+1);
            printf("ID = %d\n", list[i].Id);
            printf("titre = %s\n", list[i].title);
            printf("Description: %s\n", list[i].desc);
            printf("Date de depart: %d/%d/%d\n",list[i].deadline.tm_mday,list[i].deadline.tm_mon,list[i].deadline.tm_year);
            if (list[i].statue==1){
                printf("statue : a realiser\n");
            }else if (list[i].statue==2){
                printf("statue : en cours de realisation\n");
            }else if (list[i].statue==3){
                printf("statue : finalisee\n\n");
            }
            break ;
        }

    }

}

void rechTLT(char rech[], Lst list[], int lng)
{
    for (int i = 0; i < lng; i++)
    {
        if (strcmp(rech,list[i].title)==0)
        {
            printf("---------------------TASK%d\n",i+1);
            printf("ID = %d\n", list[i].Id);
            printf("titre = %s\n", list[i].title);
            printf("Description: %s\n", list[i].desc);
            printf("Date de depart: %d/%d/%d\n",list[i].deadline.tm_mday,list[i].deadline.tm_mon,list[i].deadline.tm_year);
            if (list[i].statue==1){
                printf("statue : a realiser\n");
            }else if (list[i].statue==2){
                printf("statue : en cours de realisation\n");
            }else if (list[i].statue==3){
                printf("statue : finalisee\n");
            }
            break;
        }
    }

}


void stats(Lst list[],int lng){
    int c=0,f=0;
    for (int i=0;i<lng;i++){
        if(list[i].statue==3){
            c++;
        }
        else if (list[i].statue==1 || list[i].statue==2){
            f++;
        }
    }
    printf("le nombre de TASK fini s'ont : %d \n" , c);
    printf("le nombre de TASK non fini s'ont : %d \n", f);
}

int main() {
    int S, nbr_ln, count = 0,index,rch,chrch,af;
    Lst list[100];
    char rh[100];
    int lng = sizeof(list)/sizeof(list[0]);
    struct dat;

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
            sup(index,list,lng,&count);

        case 4:
            if(count<=0){
                printf("rien a afficher veiller ajouter une tache");
            }else{
                Aff(count, list);
                printf ("2-trier par deadline\t3- trois jour deadline ");
            }

            break;

        case 5 :
            printf("1-cherecher par ID\t2-chercher par titre\n");
            scanf("%d",&chrch);

            do {
                if(chrch==1){
                printf("entre ID que vous voulez rechercher :  \n");
                scanf("%d", &rch);
                rechID(rch,list,lng);
                }else if (chrch==2){
                    printf("entre le titre que vous voulez rechercher :  \n");
                    scanf("%s", rh);
                    rechTLT(rh,list,lng);
                }

            }while(chrch!=1 && chrch!=2);
        case 6 :
            printf("le nombre total des TASKS est : %d \n" , count);
            stats(list,lng);

        case 7 :
            system("exit");
            break;
    }
    } while (S!=0);

}
