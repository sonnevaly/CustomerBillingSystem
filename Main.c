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
    int itemcount;
}orders;

void menul(char *file_name);
void additem();
void order();
void disphis(); /*display history*/
void searchhis();


int main(){
    int ch;
    int h_opt;
    do{
        system("cls");
        printf("\t\t-------------------------------==============-------------------------------\n");
        printf("\t\t===============================  THE 3 SHOP  ===============================\n");
        printf("\t\t-------------------------------==============-------------------------------\n\n");
        // printf("\t\t____________________________________________________________________________\n\n");
        printf("\t\t MainMenu:\n\n");
        printf("\t\t (1) Add Order\n\t\t (2) Add Item\n\t\t (3) Display Menu\n\t\t (4) History\n\t\t (5) Exit\n");
        printf("\n\t\t Enter your choice: "); 
        scanf("%d", &ch);
        fflush(stdin);
        switch(ch){
            case 1:
                order();
                break;
            case 2:
                do
                {
                    char stops;
                    system("cls");
                    printf("\n\t\t                                     =======>Add Item<=======                                     \n");
                    printf("\n\t\t__________________________________________________________________________________________________\n\n");
                    additem();
                    printf("\t\tDo you want to add other item?(y/n)");
                    scanf(" %c", &stops);
                    if(stops=='n'||stops=='N'){
                        break;
                    }else if(stops=='y'||stops=='Y'){
                        continue;
                    }
                } while (1);
                break;
            case 3:
                system("cls");
                printf("\n\t\t                            =======>Menu<=======                            \n");
                printf("\t\t____________________________________________________________________________\n");
                printf("\n\t\t____________________________________________________________________________\n");
                printf("\t\t                                   |MEAL|                                   \n");
                menul("meal.txt");
                printf("\n\t\t____________________________________________________________________________\n");
                printf("\t\t                                  |DRINK|                                   \n");
                menul("drink.txt");
                printf("\n\t\t____________________________________________________________________________\n");
                printf("\t\t                                  |DESERT|                                  \n");
                menul("desert.txt");
                system("pause");
                break;
            case 4:
                do{
                    system("cls");
                    printf("\n\t\t                                     =======>History<=======                                      \n");
                    printf("\t\t__________________________________________________________________________________________________\n\n");
                    printf("\t\t History Optios:\n\n\t\t (1) Display History\n\t\t (2) Search History\n\t\t (3) Delete History\n\t\t (4) Exit\n");
                    printf("\t\t Input option: ");
                    scanf("%d", &h_opt);
                    fflush(stdin);
                    switch (h_opt)
                    {
                        case 1:
                            disphis();
                            break;
                        case 2:
                            searchhis();
                            break;
                        case 4:
                            break;
                        default:
                            printf("\t\tNot valid!\n\n\t\t");
                            system("pause");
                            break;
                    }
                }while (h_opt!=4);
                break;
            case 5:
                exit(8);
                break;
            default:
                printf("\t\tNot valid!\n\n\t\t");
                system("pause");
        }
    }while(ch!=5);

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

void additem() {
    system("cls");
    itemmenu it;
    int n, option;
    FILE *fp = NULL;

    printf("\n\t\tPlease choose the type of item to add:\n");
    printf("\t\t(1) MEAL\n");
    printf("\t\t(2) DRINK\n");
    printf("\t\t(3) DESSERT\n");
    printf("\t\tOption: ");
    scanf("%d", &option);
    getchar(); // To consume the newline character left by scanf

    switch (option) {
        case 1:
            fp = fopen("meal.txt", "a");
            if (fp == NULL) {
                printf("Error opening file for meals.\n");
                return;
            }
            printf("\n\t\tEnter number of meals to add: ");
            scanf("%d", &n);
            getchar(); // To consume the newline character left by scanf
            for (int i = 0; i < n; i++) {
                printf("\n\t\tEnter details for meal %d:\n", i + 1);
                printf("\t\tID: ");
                scanf("%d", &it.id);
                getchar(); // To consume the newline character left by scanf
                printf("\t\tName: ");
                fgets(it.pname, sizeof(it.pname), stdin);
                it.pname[strcspn(it.pname, "\n")] = 0; // Remove newline character
                printf("\t\tPrice: ");
                scanf("%f", &it.price);
                getchar(); // To consume the newline character left by scanf
                fprintf(fp, "%d %s %.2f\n", it.id, it.pname, it.price);
            }
            break;

        case 2:
            fp = fopen("drink.txt", "a");
            if (fp == NULL) {
                printf("Error opening file for drinks.\n");
                return;
            }
            printf("\n\t\tEnter number of drinks to add: ");
            scanf("%d", &n);
            getchar(); // To consume the newline character left by scanf
            for (int i = 0; i < n; i++) {
                printf("\n\t\tEnter details for drink %d:\n", i + 1);
                printf("\t\tID: ");
                scanf("%d", &it.id);
                getchar(); // To consume the newline character left by scanf
                printf("\t\tName: ");
                fgets(it.pname, sizeof(it.pname), stdin);
                it.pname[strcspn(it.pname, "\n")] = 0; // Remove newline character
                printf("\t\tPrice: ");
                scanf("%f", &it.price);
                getchar(); // To consume the newline character left by scanf
                fprintf(fp, "%d %s %.2f\n", it.id, it.pname, it.price);
            }
            break;

        case 3:
            fp = fopen("desert.txt", "a");
            if (fp == NULL) {
                printf("Error opening file for deserts.\n");
                return;
            }
            printf("\n\t\tEnter number of desserts to add: ");
            scanf("%d", &n);
            getchar(); // To consume the newline character left by scanf
            for (int i = 0; i < n; i++) {
                printf("\n\t\tEnter details for dessert %d:\n", i + 1);
                printf("\t\tID: ");
                scanf("%d", &it.id);
                getchar(); // To consume the newline character left by scanf
                printf("\t\tName: ");
                fgets(it.pname, sizeof(it.pname), stdin);
                it.pname[strcspn(it.pname, "\n")] = 0; // Remove newline character
                printf("\t\tPrice: ");
                scanf("%f", &it.price);
                getchar(); // To consume the newline character left by scanf
                fprintf(fp, "%d %s %.2f\n", it.id, it.pname, it.price);
            }
            break;

        default:
            printf("\n\t\tInvalid option!\n");
            return;
    }

    fclose(fp);
    printf("\n\t\tItems added successfully!\n");
}


/*void additem(char *file_name){
    system("cls");
    itemmenu add;
    FILE *fp;
    printf("\n\t\t                                     =======>Add Item<=======                                     \n\n");
    printf("\n\t\t__________________________________________________________________________________________________\n\n");
    fp = fopen(file_name, "a");
    while (1)
    {
        char stop;
        printf("\t\tInput Item ID: ");
        scanf("%d", &add.id);
        fflush(stdin);
        printf("\t\tInput item name: ");
        fgets(add.pname, sizeof(add.pname), stdin);
        add.pname[strcspn(add.pname, "\n")] = 0;
        printf("\t\tInput Item price: ");
        scanf("%d", &add.price);
        fflush(stdin);
        fprintf(fp, "\n%d %s %.2f", add.id, add.pname, add.price);
        printf("\t\tDo you want to add more?(y/n)");
        scanf(" %c", &stop);
        if(stop=='n'||stop=='N'){
            break;
        }else if(stop=='y'||stop=='Y'){
            continue;
        }
        
    }
    fclose(fp);
}
*/
void order() {
    system("cls");
    orders ord;
    int i = 0;
    ord.totalitm = 0;
    ord.total = 0;
    FILE *fp = fopen("order.txt", "ab");

    if (fp == NULL) {
        printf("Error opening order file.\n");
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

    while (1) {
        itemmenu temp; //To store data temporarily
        system("cls");
        char stop;
        int menu;
        printf("\n\t\t                                   =======>PLEASE ORDER<=======                                   ");
        printf("\n\t\t__________________________________________________________________________________________________\n\n");
        printf("\n\t\tWhat would you like to order?");
        printf("\n\t\t(1) MEAL\t(2) DRINK\t(3) DESSERT\n");
        printf("\t\tChoose Menu to order: ");
        scanf("%d", &menu);

        switch (menu) {
            case 1:
                printf("\n\t\t                                   /MEAL/                                   \n");
                menul("meal.txt");
                while (1) {
                    int found = 0;
                    char buffer[200];
                    printf("\n\t\tEnter ID to order: ");
                    scanf("%d", &ord.item[i].id);
                    FILE *fp1 = fopen("meal.txt", "r");
                    while (!feof(fp1)) {
                        fgets(buffer, 200, fp1);
                        sscanf(buffer, "%d %s %f", &temp.id, temp.pname, &temp.price);
                        if (temp.id == ord.item[i].id) {
                            strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                            ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                            ord.item[i].price = temp.price;
                            found = 1;
                            break;
                        }
                    }
                    fclose(fp1);
                    if (!found) {
                        printf("\n\t\tThis is not existed!");
                        continue;
                    }
                    printf("\n\t\tHow many would you like: ");
                    scanf("%d", &ord.item[i].quantity);

                    ord.totalitm += ord.item[i].quantity;
                    ord.total += ord.item[i].quantity * ord.item[i].price;
                    i++;
                    printf("\n\t\tDo you like to order more?(y/n) ");
                    scanf(" %c", &stop);
                    if (stop == 'n' || stop == 'N') {
                        break;
                    } else if (stop == 'y' || stop == 'Y') {
                        continue;
                    } else {
                        printf("\n\t\tNot valid!");
                        printf("\n\t\tDo you like to order more?(y/n) ");
                        scanf(" %c", &stop);
                    }
                }
                break;
            case 2:
                printf("\n\t\t                                   /DRINK/                                   \n");
                menul("drink.txt");
                while (1) {
                    int found = 0;
                    char buffer[200];
                    printf("\n\t\tEnter ID to order: ");
                    scanf("%d", &ord.item[i].id);
                    FILE *fp2 = fopen("drink.txt", "r");
                    while (!feof(fp2)) {
                        fgets(buffer, 200, fp2);
                        sscanf(buffer, "%d %s %f", &temp.id, temp.pname, &temp.price);
                        if (temp.id == ord.item[i].id) {
                            strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                            ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                            ord.item[i].price = temp.price;
                            found = 1;
                        }
                    }
                    fclose(fp2);
                    if (!found) {
                        printf("\n\t\tThis is not existed!");
                        continue;
                    }
                    printf("\n\t\tHow many would you like: ");
                    scanf("%d", &ord.item[i].quantity);
                    ord.totalitm += ord.item[i].quantity;
                    ord.total += ord.item[i].quantity * ord.item[i].price;
                    i++;
                    printf("\n\t\tDo you like to order more?(y/n) ");
                    scanf(" %c", &stop);
                    if (stop == 'n' || stop == 'N') {
                        break;
                    } else if (stop == 'y' || stop == 'Y') {
                        continue;
                    } else {
                        printf("\n\t\tNot valid!");
                        printf("\n\t\tDo you like to order more?(y/n) ");
                        scanf(" %c", &stop);
                    }
                }
                break;
            case 3:
                printf("\n\t\t                                  /DESSERT/                                  \n");
                menul("desert.txt");
                while (1) {
                    int found = 0;
                    char buffer[200];
                    printf("\n\t\tEnter ID to order: ");
                    scanf("%d", &ord.item[i].id);
                    FILE *fp3 = fopen("desert.txt", "r");
                    while (!feof(fp3)) {
                        fgets(buffer, 200, fp3);
                        sscanf(buffer, "%d %s %f", &temp.id, temp.pname, &temp.price);
                        if (temp.id == ord.item[i].id) {
                            strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                            ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                            ord.item[i].price = temp.price;
                            found = 1;
                        }
                    }
                    fclose(fp3);
                    if (!found) {
                        printf("\n\t\tThis is not existed!");
                        continue;
                    }
                    printf("\n\t\tHow many would you like: ");
                    scanf("%d", &ord.item[i].quantity);
                    ord.totalitm += ord.item[i].quantity;
                    ord.total += ord.item[i].quantity * ord.item[i].price;
                    i++;
                    printf("\n\t\tDo you like to order more?(y/n) ");
                    scanf(" %c", &stop);
                    if (stop == 'n' || stop == 'N') {
                        break;
                    } else if (stop == 'y' || stop == 'Y') {
                        continue;
                    }
                }
                break;
            default:
                continue;
        }
        printf("\n\t\tDo you like to order anything else?(y/n) ");
        scanf(" %c", &stop);
        if (stop == 'n' || stop == 'N') {
            break;
        } else if (stop == 'y' || stop == 'Y') {
            continue;
        }
    }

    // Display receipt
    system("cls");
    ord.itemcount = i;
    printf("\n\t\tReceipt\n");
    printf("\t\t========================================================\n");
    printf("\t\t%-20s %s\n", "Customer:", ord.name);
    printf("\t\t%-20s %s\n", "Phone:", ord.phone);
    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t%-30s %-15s %-5s\n", "Item_Name", "Quantity", "Price");
    printf("\t\t--------------------------------------------------------\n");
    for (int j = 0; j < ord.itemcount; j++) {
        printf("\t\t%-30s %-15d $%-5.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].price);
    }

    printf("\t\t--------------------------------------------------------\n");
    printf("\t\t%-30s %-15d $%-5.2f\n", "Total:", ord.totalitm, ord.total);
    printf("\t\t%-45s  $%-5.2f\n", "Discounted(20%%):", ord.total * 0.8);
    printf("\t\t========================================================\n");

    fwrite(&ord, sizeof(ord), 1, fp);
    fclose(fp);

    system("pause");
}


//bn
void disphis(){
    orders ord;
    int r_num=1;
    FILE *fp;
    fp=fopen("order.txt", "rb");
    if (fp == NULL) {
        printf("Error opening order file.\n");
        return;
    }

    system("cls");
    while(fread(&ord, sizeof(orders), 1, fp)){
        printf("\n\t\t                       Receipt %d\n", r_num);
        r_num++;
        printf("\t\t========================================================\n");
        printf("\t\t%-20s %s\n","Customer:", ord.name);
        printf("\t\t%-20s %s\n","Phone:", ord.phone);
        printf("\t\t--------------------------------------------------------\n");
        printf("\t\t%-30s %-15s %-5s\n","Item_Name", "Quantity","Price");
        printf("\t\t--------------------------------------------------------\n");
        for(int j=0; j<ord.itemcount; j++){
            printf("\t\t%-30s %-15d $%-5.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].price);
        }
        
        printf("\t\t--------------------------------------------------------\n");
        printf("\t\t%-30s %-15d $%-5.2f\n","Total:", ord.totalitm, ord.total);
        printf("\t\t%-45s  $%-5.2f\n","Discounted(20%%):", ord.total*0.8);
        printf("\t\t========================================================\n\n");
        printf("\t------------------------------------------------------------------------\n\n");
    }
    fclose(fp);
    
    system("pause");


}

void searchhis(){
    while(1){
        system("cls");
        orders ord;
        char name[50], phone[11];
        int r_num=1, found=0;
        char stop;

        FILE *fp;
        fp=fopen("order.txt", "rb");
        if (fp == NULL) {
            printf("Error opening order file.\n");
            return;
        }

        printf("\t\tInput customer information:\n");
        printf("\t\t--------------------------------------------------------\n");
        printf("\t\tInput the customer name:");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;

        printf("\t\tInput the customer phone number:");
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = 0;
        system("cls");

        while(fread(&ord, sizeof(orders), 1, fp)){
            if (!strcmp(ord.phone, phone) || !strcmp(ord.name, name))
            {
                printf("\n\t\t                       Receipt %d\n", r_num);
                printf("\t\t========================================================\n");
                printf("\t\t%-20s %s\n","Customer:", ord.name);
                printf("\t\t%-20s %s\n","Phone:", ord.phone);
                printf("\t\t--------------------------------------------------------\n");
                printf("\t\t%-30s %-15s %-5s\n","Item_Name", "Quantity","Price");
                printf("\t\t--------------------------------------------------------\n");
                for(int j=0; j<ord.itemcount; j++){
                    printf("\t\t%-30s %-15d $%-5.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].price);
                }
                
                printf("\t\t--------------------------------------------------------\n");
                printf("\t\t%-30s %-15d $%-5.2f\n","Total:", ord.totalitm, ord.total);
                printf("\t\t%-45s  $%-5.2f\n","Discounted(20%%):", ord.total*0.8);
                printf("\t\t========================================================\n\n");
                printf("\t\t--------------------------------------------------------\n\n");
                found=1;  
            }
            r_num++;
        }
        fclose(fp);
        if (!found)
        {
            printf("Not existed!\n");
            system("pause");
            break;
        }
        printf("\n\t\tDo you want to search again?(y/n) ");
        scanf(" %c", &stop);
        fflush(stdin);
        if(stop=='n'||stop=='N'){
            break;
        }else if(stop=='y'||stop=='Y'){
            continue;
        }        
    }
    

}