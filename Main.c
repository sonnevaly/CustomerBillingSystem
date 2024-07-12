#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char pname[50]; /*Product name*/
    float price;
}itemmenu;

typedef struct {
    int id;
    char pname[50]; /*Product name*/
    int quantity;
    float price;
}itemorder;

typedef struct {
    char name[50];
    char date[20];
    char phone[11];
    itemorder item[100];
    int totalitm;
    float total;
}orders;

void menul(char *file_name);
void oper(char *file_name); //Operation
void order();
void disphis(); /*display history*/


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
                printf("\t\tNot valid!\n\n\t\t");
                system("pause");
        }
    }while(ch!=3);
    return 0;
}


void menul(char *file_name){
    itemmenu m;
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
        fgets(buffer, 200, fp);
        sscanf(buffer,"%d %s %f", &m.id, &m.pname, &m.price);
        printf("\t\t %-20d %-40s %-7.2f$\n", m.id, m.pname, m.price);
    }while(!feof(fp));

    printf("\t\t____________________________________________________________________________\n");
}


// Valy
void order() {
    system("cls");
    orders ord;
    int i=0, itemcount=0;
    ord.totalitm=0;
    ord.total=0;
    FILE *fp, *fp1, *fp2, *fp3;
    fp = fopen("order.txt", "ab");
    fp1 = fopen("meal.txt", "r");
    fp2 = fopen("drink.txt", "r");
    fp3 = fopen("desert.txt", "r");

    if (fp == NULL) {
        printf("Error opening order file.\n");
        return;
    }

    if (fp1 == NULL || fp2 == NULL || fp3 == NULL) {
        printf("Error opening menu files.\n");
        return;
    }

    
    printf("\n\t\t                                   =======>PLEASE ORDER<=======                                   \n\n");
    printf("\n\t\t__________________________________________________________________________________________________\n\n");
    // Ask for the customer's name and phone number
    printf("\n\n\t\tEnter your name: ");
    fgets(ord.name, sizeof(ord.name), stdin);
    ord.name[strcspn(ord.name, "\n")] = 0; 
    
    printf("\t\tEnter your phone number: ");
    fgets(ord.phone, sizeof(ord.phone), stdin);
    ord.phone[strcspn(ord.phone, "\n")] = 0; 

    
    // int orderCount = 0;
    // int totalItems = 0;
    // float totalPrice = 0.0;
    // int found = 0;
    // char buffer[200];


    while(1){
        itemmenu temp; //To store data temperary
        system("cls");
        char stop;
        int menu;
        printf("\n\t\t                                   =======>PLEASE ORDER<=======                                   ");
        printf("\n\t\t__________________________________________________________________________________________________\n\n");
        printf("\n\t\tWhat would you like to order?");
        printf("\n\t\t(1) MEAL\t(2) DRINK\t(3) DESERT\n");
        printf("\t\tChoose Menu to order: ");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                printf("\n\t\t                                   /MEAL/                                   \n");
                menul("meal.txt");
                while(1){
                        // con_loop1:
                        int found=0;
                        char buffer[200];
                        char stop;
                        printf("\n\t\tEnter ID to order: ");
                        scanf("%d", &ord.item[i].id);
                        while (!feof(fp1)){
                            fgets(buffer, 200, fp1);
                            sscanf(buffer,"%d %s %f", &temp.id, &temp.pname, &temp.price);

                            if(temp.id == ord.item[i].id){
                                strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                                ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                                ord.item[i].price = temp.price;
                                found=1;
                                break;
                            }
                        }
                        if (!found){
                            printf("\n\t\tThis is not existed!\n");
                            continue;
                        }
                        printf("\n\t\tHow many would you like: ");
                        scanf("%d", &ord.item[i].quantity);

                        ord.totalitm += ord.item[i].quantity; 
                        ord.total += ord.item[i].quantity *  ord.item[i].price;
                        i++;
                        printf("\n\t\tDo you like to order more?(y/n) ");
                        scanf(" %c", &stop);
                        if(stop=='n'||stop=='N'){
                            break;
                        }else if(stop=='y'||stop=='Y'){
                            continue;
                        }else{
                            printf("\n\t\tNot valid!");
                            printf("\n\t\tDo you like to order more?(y/n) ");
                            scanf(" %c", &stop);
                        }
                        
                    
                }
                break;
            case 2:
                printf("\n\t\t                                   /DRINK/                                   \n");
                menul("drink.txt");
                while(1){
                        // con_loop2:
                        int found=0;
                        char buffer[200];
                        char stop;
                        printf("\n\t\tEnter ID to order: ");
                        scanf("%d", &ord.item[i].id);
                        while (!feof(fp2))
                        {
                            fgets(buffer, 200, fp2);
                            sscanf(buffer,"%d %s %f", &temp.id, &temp.pname, &temp.price);
                            if(temp.id == ord.item[i].id){
                                strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                                ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                                ord.item[i].price = temp.price;
                                found=1;
                            }
                        }
                        if (!found){
                            printf("\n\t\tThis is not existed!\n");
                            continue;
                        }
                        printf("\n\t\tHow many would you like: ");
                        scanf("%d", &ord.item[i].quantity);
                        ord.totalitm += ord.item[i].quantity; 
                        ord.total += ord.item[i].quantity *  ord.item[i].price;
                        i++;
                        printf("\n\t\tDo you like to order more?(y/n) ");
                        scanf(" %c", &stop);
                        if(stop=='n'||stop=='N'){
                            break;
                        }else if(stop=='y'||stop=='Y'){
                            continue;
                        }else{
                            printf("\n\t\tNot valid!");
                            printf("\n\t\tDo you like to order more?(y/n) ");
                            scanf(" %c", &stop);
                        }
                        
                    
                }
                break;
            case 3:
                printf("\n\t\t                                  /DESERT/                                  \n");
                menul("desert.txt");
                while(1){
                        // con_loop3:
                        int found=0;
                        char buffer[200];
                        char stop;
                        printf("\n\t\tEnter ID to order: ");
                        scanf("%d", &ord.item[i].id);
                        while (!feof(fp3))
                        {
                            fgets(buffer, 200, fp3);
                            sscanf(buffer,"%d %s %f", &temp.id, &temp.pname, &temp.price);
                            if(temp.id == ord.item[i].id){
                                strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                                ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                                ord.item[i].price = temp.price;
                                found=1;
                            }
                        }
                        if (!found){
                            printf("\n\t\tThis is not existed!\n");
                            continue;
                        }
                        printf("\n\t\tHow many would you like: ");
                        scanf("%d", &ord.item[i].quantity);
                        ord.totalitm += ord.item[i].quantity; 
                        ord.total += ord.item[i].quantity *  ord.item[i].price;
                        i++;
                        printf("\n\t\tDo you like to order more?(y/n) ");
                        scanf(" %c", &stop);
                        if(stop=='n'||stop=='N'){
                            break;
                        }else if(stop=='y'||stop=='Y'){
                            continue;
                        }else{
                            printf("\n\t\tNot valid!");
                            printf("\n\t\tDo you like to order more?(y/n) ");
                            scanf(" %c", &stop);
                        }
                        
                    
                }
                break;
            default:
                continue;
        }
        printf("\n\t\tDo you like to order anything else?(y/n) ");
        scanf(" %c", &stop);
        if(stop=='n'||stop=='N'){
            break;
        }else if(stop=='y'||stop=='Y'){
            continue;
        }else{
            printf("\n\t\tNot valid!");
            printf("\n\t\tDo you like to order anything else?(y/n) ");
            scanf(" %c", &stop);
        }
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    // Display receipt
    system("cls");
    printf("i is %d", i);
    printf("\n\t\t\t\tReceipt\n");
    printf("\t\t=====================================================\n");
    printf("\t\t %-30s %s\n","Customer:", ord.name);
    printf("\t\t %-30s %s\n","Phone:", ord.phone);
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t %-30s %-15s %-5s\n","Item_Name", "Quantity","Price");
    printf("\t\t-----------------------------------------------------\n");
    for(int j=0; j<i; j++){
        printf("\t\t %-30s %-15d %-5.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].price);
    }
    
    // for (int i = 0; i < orderCount; i++) {
    //     printf("\t\t%s x%d - $%.2f\n", orders[i].name, orders[i].quantity, orders[i].price);
    // }
    printf("\t\t-----------------------------------------------------\n");
    printf("\t\t %-30s %-15d %-5.2f\n","Total:", ord.totalitm, ord.total);
    printf("\t\t=====================================================\n");

    fwrite(&ord, sizeof(orders), 1, fp);
    fclose(fp);
    printf("\n\n\t\t");
    system("pause");

}
