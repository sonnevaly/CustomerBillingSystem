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

            case 2:
                order();
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

// Valy
void order() {
    system("cls");
    menul(); 

    char customerName[50];
    char phoneNumber[15];
    int id, quantity;

    // Ask for the customer's name and phone number
    printf("\n\nEnter your name: ");
    fgets(customerName, sizeof(customerName), stdin);
    customerName[strcspn(customerName, "\n")] = 0; 

    printf("Enter your phone number: ");
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
}