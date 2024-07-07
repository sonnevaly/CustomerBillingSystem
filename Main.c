#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct menulist{
    int id;
    char pname[50]; /*Product name*/
    float price;
}menu;

menu m;

void menul();
void order();
void disphis(); /*display history*/
void Additem();

int main(){
    int ch = 0;
    do{
        system("cls");
        printf("\t\t============================================================================\n");
        printf("\t\t=============================== /THE 3 SHOP/ ===============================\n");
        printf("\t\t============================================================================\n\n");
        printf("\t\t____________________________________________________________________________\n\n");
        printf("\t\tMainMenu:\n\n");
        printf("\t\t1. Menu List\n\t\t2. Add Order\n\t\t3. History\n\t\t4. Exit\n");
        printf("\n\t\tEnter your choice: "); 
        scanf("%d", &ch);
        fflush(stdin);
        switch(ch){
            case 1:
                menul();
                break;
            case 4:
                exit(8);
        }
    }while(ch!=4);
    return 0;
}


void menul(){
    system("cls");

    printf("\t\t                                =>MENULIST<=                                \n");
    printf("\t\t____________________________________________________________________________\n\n");
    FILE *fp1, *fp2, *fp3;
    fp1=fopen("meal.txt", "r");
    fp2=fopen("drink.txt", "r");
    fp3=fopen("desert.txt", "r");

    if (fp1==NULL){
        return;
    }
    if (fp2==NULL){
        return;
    }
    if (fp3==NULL){
        return;
    }
    printf("\n\t\t                                   /MEAL/                                   \n");
    printf("\t\t____________________________________________________________________________\n");
    printf("\t\t%-20s %-40s %-10s","ID","Name","Price");
    printf("\n\t\t____________________________________________________________________________\n");

    char buffer[200];
    do{
        menu m;
        fgets(buffer, 200, fp1);
        sscanf(buffer,"%d %s %f", &m.id, &m.pname, &m.price);
        printf("\t\t%-20d %-40s %-7.2f$\n", m.id, m.pname, m.price);
    }while(!feof(fp1));

    printf("\n\t\t                                  /DRINKS/                                  \n");
    printf("\t\t____________________________________________________________________________\n");
    printf("\t\t%-20s %-40s %-10s","ID","Name","Price");
    printf("\n\t\t____________________________________________________________________________\n");

    do{
        menu m;
        fgets(buffer, 200, fp2);
        sscanf(buffer,"%d %s %f", &m.id, &m.pname, &m.price);
        printf("\t\t%-20d %-40s %-7.2f$\n", m.id, m.pname, m.price);
    }while(!feof(fp2));
    
    printf("\n\t\t                                  /DESERT/                                  \n");
    printf("\t\t____________________________________________________________________________\n");
    printf("\t\t%-20s %-40s %-10s","ID","Name","Price");
    printf("\n\t\t____________________________________________________________________________\n");

    do{
        menu m;
        fgets(buffer, 200, fp3);
        sscanf(buffer,"%d %s %f", &m.id, &m.pname, &m.price);
        printf("\t\t%-20d %-40s %-7.2f$\n", m.id, m.pname, m.price);
    }while(!feof(fp3));
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("\n\t\tPress any key to go back!\t\t");
    getchar();
    return;
}





// void menul(){
    
//     system("cls");
//     FILE *p1;
    
//     p1= fopen("meal.txt", "r");
//     if (p1 == NULL) {
//         printf("Error opening meal.txt\n");
//         return;
//     }
//     // p2= fopen("drink.txt", "rb");
//     // p3= fopen("desert.txt", "rb");
//     printf("\t\t%-10s %-20s %-10s","ID","Name","Price");
//     printf("\n\t\t____________________________________________________________________________\n");
    
//     while(fread(&m,sizeof(m),1,p1)==1){
//         printf("\t\t%-10d %-20s %-10.2f\n", m.id, m.pname, m.price);
//     }
    
//     fclose(p1);
//     // fclose(p2);
//     // fclose(p3);
// }


// void menul() {
//     FILE *p1;
//     system("cls");
    
    

//     printf("\t\t------------------------------------------------------------\n");
//     printf("\t\t%-10s %-20s %-10s\n", "ID", "Name", "Price");
//     printf("\t\t------------------------------------------------------------\n");
//     p1 = fopen("meal.txt", "rb");
//     // if (p1 == NULL) {
//     //     printf("Error opening meal.dat\n");
//     //     return;
//     // }
//     while (fread(&m, sizeof(m), 1, p1) == 1) {
//         printf("\t\t%-10d %-20s %-10.2f\n", m.id, m.pname, m.price);
//     }

//     fclose(p1);
// }

// void Additem(){
//     system("cls");
//     FILE *fp;
//     fp=fopen("drink.txt", "ab");
//     printf("Enter Item id: ");
//     scanf("%d", &m.id);
//     printf("Enter Item name: ");
//     fflush(stdin);
//     gets(m.pname);
//     printf("Enter the Price: ");
//     fflush(stdin);
//     scanf("%d", &m.price);
//     fwrite(&m,sizeof(m),1,fp);
//     fclose(fp);
// }