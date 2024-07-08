#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct menulist{
    int id;
    char pname[50]; /*Product name*/
    float price;
}menu;

menu m;

void menul(char *file_name);
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
        printf("\t\t1. Add Order\n\t\t2. History\n\t\t3. Exit\n");
        printf("\n\t\tEnter your choice: "); 
        scanf("%d", &ch);
        fflush(stdin);
        switch(ch){
            case 1:
                order();
                break;
            // case 2:
                    
            case 3:
                exit(8);
                break;
            default:
                printf("\t\tNot valid!");
                getchar();
        }
    }while(ch!=3);
    return 0;
}


void menul(char *file_name){
    FILE *fp;
    fp=fopen(file_name, "r");


    if (fp==NULL){
        return;
    }
    char buffer[200];
    
    
    printf("\t\t____________________________________________________________________________\n");
    printf("\t\t %-20s %-40s %-10s","ID","Name","Price");
    printf("\n\t\t____________________________________________________________________________\n");

    
    do{
        menu m;
        fgets(buffer, 200, fp);
        sscanf(buffer,"%d %s %f", &m.id, &m.pname, &m.price);
        printf("\t\t %-20d %-40s %-7.2f$\n", m.id, m.pname, m.price);
    }while(!feof(fp));

    printf("\t\t____________________________________________________________________________\n");
}

// Valy
void order() {
    system("cls");
    char stop;
    int menu;
    char customerName[50];
    char phoneNumber[15];
    int id, quantity;

    printf("\n\t\t                                   =======>PLEASE ORDER<=======                                   \n\n");
    printf("\n\t\t__________________________________________________________________________________________________\n\n");
    // Ask for the customer's name and phone number
    printf("\n\n\t\tEnter your name: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = 0; 

    printf("\t\tEnter your phone number: ");
    fgets(phoneNumber, sizeof(phoneNumber), stdin);
    phoneNumber[strcspn(phoneNumber, "\n")] = 0; 

    FILE *fp1, *fp2, *fp3;
    fp1 = fopen("meal.txt", "r");
    fp2 = fopen("drink.txt", "r");
    fp3 = fopen("desert.txt", "r");

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        printf("Error opening menu files.\n");
        return;
    }

    // Initialize variables for order processing
    int totalItems = 0;
    float totalPrice = 0.0;
    int found = 0;
    char buffer[200];

    while(1){
        system("cls");
        char stop;
        printf("\n\t\t                                   =======>PLEASE ORDER<=======                                   ");
        printf("\n\t\t__________________________________________________________________________________________________\n\n");
        printf("\n\t\tWhat would you like to order?");
        printf("\n\t\t(1) MEAL\t(2) DRINK\t(3) DESERT\n\t\t");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                printf("\n\t\t                                   /MEAL/                                   \n");
                menul("meal.txt");
                break;
            case 2:
                printf("\n\t\t                                   /DRINK/                                   \n");
                menul("drink.txt");
                break;
            case 3:
                printf("\n\t\t                                  /DESERT/                                  \n");
                menul("desert.txt");
                break; 
        }
        while(1){
            printf("\n\t\tInter ID to order: ");
            scanf("%d", &id);
            printf("\n\t\tDo you like to order more?(y/n) ");
            scanf(" %c", &stop);
            if(stop=='n'||stop=='N')
            break;
        }
        printf("\n\t\tDo you like to order anything else?(y/n) ");
        scanf(" %c", &stop);
        if(stop=='n'||stop=='N')
        break;
    }
    
    

    printf("\n\n\t\t");
    system("pause");

} 