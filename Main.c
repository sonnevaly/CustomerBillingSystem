#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//system("pause"); used for menu, receipt, ect... to keep display until any key has been clicked
//system("cls"); clears previous screen

typedef struct {
    int id;
    char pname[50]; /*Product name*/
    float price;
    float discount;
}itemmenu;

typedef struct {
    int id;
    char pname[50]; /*Product name*/
    int quantity;
    float price;
    float discount;
}itemorder;

typedef struct {
    char name[50];
    char date[20];
    char phone[11];
    itemorder item[100];
    int totalitm;  //Total item ordered
    float total; //Total price
    float discounted; //Total price after dicount
    int itemcount; //To store how many time you order
    char paymentmode[15]; //cash, credit card or wallet

}orders;

void menul(char *file_name);
void additem(int *found);
void order();
void disphis(); /*display history*/
void searchhis();



//Main (Danika)
int main(){
    int ch;
    int h_opt;
    do{
        system("cls");
        printf("\t\t-------------------------------==============-------------------------------\n");
        printf("\t\t===============================  THE 3 SHOP  ===============================\n");
        printf("\t\t-------------------------------==============-------------------------------\n\n");
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
                    int found = 0;
                    additem(&found);
                    if (found == 1)
                    {
                        break;
                    }
                    printf("\n\t\tItems added successfully!\n");
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
                printf("\n\t\t                                 =======>Menu<=======                                 \n");
                printf("\t\t______________________________________________________________________________________\n");
                printf("\n\t\t______________________________________________________________________________________\n");
                printf("\t\t                                        |MEAL|                                        \n");
                menul("meal.txt");
                printf("\n\t\t______________________________________________________________________________________\n");
                printf("\t\t                                       |DRINK|                                        \n");
                menul("drink.txt");
                printf("\n\t\t______________________________________________________________________________________\n");
                printf("\t\t                                       |DESERT|                                       \n");
                menul("desert.txt");
                system("pause");
                break;
            case 4:
                do{
                    system("cls");
                    printf("\n\t\t                                     =======>History<=======                                      \n");
                    printf("\t\t__________________________________________________________________________________________________\n\n");
                    printf("\t\t History Optios:\n\n\t\t (1) Display History\n\t\t (2) Search History\n\t\t (3) Exit\n");
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
                        case 3:
                            break;
                        default:
                            printf("\t\tNot valid!\n\n\t\t");
                            system("pause");
                            break;
                    }
                }while (h_opt!=3);
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


//MENU  (San Muoykea)
void menul(char *file_name){
    itemmenu m;
    FILE *fp;
    fp=fopen(file_name, "r");


    if (fp==NULL){
        return;
    }
    char buffer[200];
    
    
    printf("\t\t______________________________________________________________________________________\n");
    printf("\t\t %-20s %-40s %-10s %-10s","ID","Name","Price","Dicount");
    printf("\n\t\t______________________________________________________________________________________\n");

    
    do{
        fgets(buffer, 200, fp);
        sscanf(buffer,"%d %s %f %f", &m.id, &m.pname, &m.price, &m.discount);
        printf("\t\t %-20d %-40s $%-10.2f %-5.2f %%\n", m.id, m.pname, m.price, m.discount);
    }while(!feof(fp));

    printf("\t\t______________________________________________________________________________________\n");
}


//Add Item (Bunnaroth)
void additem(int *found) {
    system("cls");
    printf("\n\t\t                                     =======>Add Item<=======                                     \n");
    printf("\n\t\t__________________________________________________________________________________________________\n\n");
    itemmenu it;
    int n, option;
    FILE *fp = NULL;

    printf("\n\t\tPlease choose the type of item to add:\n\n");
    printf("\t\t(1) MEAL\n");
    printf("\t\t(2) DRINK\n");
    printf("\t\t(3) DESSERT\n");
    printf("\t\t(4) Exit\n\n");
    printf("\t\tOption: ");
    scanf("%d", &option);
    getchar(); // To consume the newline character left by scanf

    switch (option) {
        case 1:
            system("cls");
            printf("\n\t\t                                     =======>Add Item<=======                                     \n");
            printf("\n\t\t__________________________________________________________________________________________________\n\n");
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
                printf("\t\tDiscount: ");
                scanf("%f", &it.discount);
                getchar(); // To consume the newline character left by scanf
                fprintf(fp, "\n%d %s %.2f %.2f", it.id, it.pname, it.price, it.discount);
            }
            break;

        case 2:
            system("cls");
            printf("\n\t\t                                     =======>Add Item<=======                                     \n");
            printf("\n\t\t__________________________________________________________________________________________________\n\n");
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
                getchar(); 
                printf("\t\tName: ");
                fgets(it.pname, sizeof(it.pname), stdin);
                it.pname[strcspn(it.pname, "\n")] = 0; // Remove newline character
                printf("\t\tPrice: ");
                scanf("%f", &it.price);
                getchar(); 
                printf("\t\tDiscount: ");
                scanf("%f", &it.discount);
                getchar(); // To consume the newline character left by scanf
                fprintf(fp, "\n%d %s %.2f %.2f", it.id, it.pname, it.price, it.discount);
            }
            break;

        case 3:
            system("cls");
            printf("\n\t\t                                     =======>Add Item<=======                                     \n");
            printf("\n\t\t__________________________________________________________________________________________________\n\n");
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
                getchar(); 
                printf("\t\tName: ");
                fgets(it.pname, sizeof(it.pname), stdin);
                it.pname[strcspn(it.pname, "\n")] = 0; 
                printf("\t\tPrice: ");
                scanf("%f", &it.price);
                getchar();
                printf("\t\tDiscount: ");
                scanf("%f", &it.discount);
                getchar(); // To consume the newline character left by scanf
                fprintf(fp, "\n%d %s %.2f %.2f", it.id, it.pname, it.price, it.discount);
            }
            break;
        case 4:
            *found = 1;
            break;
        default:
            printf("\n\t\tInvalid option!\n");
            break;
    }

    fclose(fp);
}



//Order  (Sitharath)
void order() {
    system("cls");
    orders ord;
    int i = 0;
    ord.totalitm = 0;
    ord.total = 0;
    ord.discounted = 0;
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
            //All cases are the same just used different Type of food(Meal, Drink or Desert)
            case 1:
                printf("\n\t\t                                   /MEAL/                                   \n");
                menul("meal.txt");
                while (1) {
                    int found = 0;
                    char buffer[200]; //To store every line of information from file
                    printf("\n\t\tEnter ID to order: ");
                    scanf("%d", &ord.item[i].id);
                    FILE *fp1 = fopen("meal.txt", "r");
                    while (!feof(fp1)) {
                        fgets(buffer, 200, fp1); //Read a line from file
                        sscanf(buffer, "%d %s %f %f", &temp.id, temp.pname, &temp.price, &temp.discount); //Read the line from buffer and put each data to its own variable in Struct
                        
                        //Compare the Input id and id from file
                        if (temp.id == ord.item[i].id) {
                            strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                            ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                            ord.item[i].price = temp.price;
                            ord.item[i].discount = temp.discount;
                            found = 1;
                            break;
                        }
                    }
                    fclose(fp1);
                    if (!found) {
                        printf("\n\t\tThis is not existed!");
                        continue;
                    }
                    //If item not existed loop again


                    //If exist ask for quantity
                    printf("\n\t\tHow many would you like: ");
                    scanf("%d", &ord.item[i].quantity);

                    //Calculate total item and total price
                    ord.totalitm += ord.item[i].quantity;
                    ord.total += ord.item[i].quantity * ord.item[i].price;

                    //Calculate total price after every item discount
                    ord.discounted += ord.item[i].quantity * (ord.item[i].price * (1 - ord.item[i].discount/100));

                    //Index of array structure
                    i++;

                    //Ask for another order
                    printf("\n\t\tDo you like to order more?(y/n) ");
                    scanf(" %c", &stop);
                    if (stop == 'n' || stop == 'N') {
                        break;
                    } else if (stop == 'y' || stop == 'Y') {
                        continue;
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
                        sscanf(buffer, "%d %s %f %f", &temp.id, temp.pname, &temp.price, &temp.discount);
                        if (temp.id == ord.item[i].id) {
                            strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                            ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                            ord.item[i].price = temp.price;
                            ord.item[i].discount = temp.discount;
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
                    ord.discounted += ord.item[i].quantity * (ord.item[i].price * (1 - ord.item[i].discount/100));
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
                        sscanf(buffer, "%d %s %f %f", &temp.id, temp.pname, &temp.price, &temp.discount);
                        if (temp.id == ord.item[i].id) {
                            strncpy(ord.item[i].pname, temp.pname, sizeof(ord.item[i].pname) - 1);
                            ord.item[i].pname[sizeof(ord.item[i].pname) - 1] = '\0';
                            ord.item[i].price = temp.price;
                            ord.item[i].discount = temp.discount;
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
                    ord.discounted += ord.item[i].quantity * (ord.item[i].price * (1 - ord.item[i].discount/100));
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
        printf("\n\t\tDo you like to order anything else?(y/n) ");//To order other type like: Meal, Drink or Desert
        scanf(" %c", &stop);
        if (stop == 'n' || stop == 'N') {
            break;
        } else if (stop == 'y' || stop == 'Y') {
            continue;
        }
    }

    // Choose Payment mode
    while (1)
    {
        system("cls");
        int ch; //Payment choice
        printf("\t\tHow would you like to pay?\n\t\t(1) Cash \t(2) Credit_Card \t(3) Wallet\n");
        printf("\t\tInput your choice: ");
        scanf("%d", &ch);
        if (ch==1)
        {
            strncpy(ord.paymentmode, "Cash", sizeof(ord.paymentmode) - 1); //Cash: normal paper of money
            ord.paymentmode[sizeof(ord.paymentmode) - 1] = '\0';
            break;
        }else if (ch==2)
        {
            strncpy(ord.paymentmode, "Credit Card", sizeof(ord.paymentmode) - 1); //Credit Card: Physical card
            ord.paymentmode[sizeof(ord.paymentmode) - 1] = '\0';
            break;
        }else if (ch==3)
        {
            strncpy(ord.paymentmode, "Wallet", sizeof(ord.paymentmode) - 1); //Wallet: Electronic wallet for example: ABA, ACleda, ...
            ord.paymentmode[sizeof(ord.paymentmode) - 1] = '\0';
            break;
        }else
        {
            printf("\t\tNot valid! Please try again!\n\n");
            system("pause");
            continue; //If Payment mode not existed ask to input again
        }
        
    }
    
    
    

    // Display receipt
    system("cls");
    ord.itemcount = i;
    printf("\t\t\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t                              Receipt\n");
    printf("\t\t\t\t=====================================================================\n");
    printf("\t\t\t\t%-20s %s\n", "Customer:", ord.name);
    printf("\t\t\t\t%-20s %s\n", "Phone:", ord.phone);
    printf("\t\t\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t%-30s %-15s %-7s  %-5s\n", "Item_Name", "Quantity", "Disc", "Price");
    printf("\t\t---------------------------------------------------------------------\n");
    for (int j = 0; j < ord.itemcount; j++) {
        printf("\t\t\t\t%-30s %-15d %-5.2f %%  $%-7.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].discount, ord.item[j].price);
    }

    printf("\t\t\t\t---------------------------------------------------------------------\n");
    printf("\t\t\t\t%-30s %-24d $%-5.2f\n", "Total:", ord.totalitm, ord.total);
    printf("\t\t\t\t%-55s $%-5.2f\n", "Discounted:", ord.discounted);
    printf("\t\t\t\t%-55s %-15s\n", "PaymentMode:", ord.paymentmode);
    printf("\t\t\t\t=====================================================================\n");

    fwrite(&ord, sizeof(ord), 1, fp);
    fclose(fp);

    system("pause");
}


//Display history (Danika)
void disphis(){
    orders ord;   //Structure to store receipt from file
    int r_num=1;  //Receipt Number
    FILE *fp;
    fp=fopen("order.txt", "rb");
    if (fp == NULL) {
        printf("Error opening order file.\n");
        return;
    }

    //Display receipt
    system("cls");
    while(fread(&ord, sizeof(orders), 1, fp))
    {
        printf("\t\t\t\t---------------------------------------------------------------------\n");   
        printf("\t\t\t\t                              Receipt %d\n", r_num);
        r_num++;
        printf("\t\t\t\t=====================================================================\n");
        printf("\t\t\t\t%-20s %s\n", "Customer:", ord.name);
        printf("\t\t\t\t%-20s %s\n", "Phone:", ord.phone);
        printf("\t\t\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t%-30s %-15s %-7s  %-5s\n", "Item_Name", "Quantity", "Disc", "Price");
        printf("\t\t\t\t---------------------------------------------------------------------\n");
        for (int j = 0; j < ord.itemcount; j++) {
            printf("\t\t\t\t%-30s %-15d %-5.2f %%  $%-7.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].discount, ord.item[j].price);
        }

        printf("\t\t\t\t---------------------------------------------------------------------\n");
        printf("\t\t\t\t%-30s %-24d $%-5.2f\n", "Total:", ord.totalitm, ord.total);
        printf("\t\t\t\t%-55s $%-5.2f\n", "Discounted:", ord.discounted);
        printf("\t\t\t\t%-55s %-15s\n", "PaymentMode:", ord.paymentmode);
        printf("\t\t\t\t=====================================================================\n\n");
        printf("\t\t-----------------------------------------------------------------------------------------------------\n");
    }
    fclose(fp);
    
    system("pause");


}


//Search History (Valy)
void searchhis(){
    while(1){
        system("cls");
        orders ord;  //Structure to store receipt from file
        char name[50];
        char phone[11];
        int r_num=1;  //Receipt Number
        int found=0;  //For checking existence of receipt
        char stop;  //For Searching again

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

        //Display receipt
        while(fread(&ord, sizeof(orders), 1, fp)) //Read struct from file until the end of file
        {
            if (!strcmp(ord.phone, phone) || !strcmp(ord.name, name)) //If phone number or name match the receipt display it. If name or phone are same they will display. if user want to specify input both name and phone number
            {
                printf("\t\t\t\t---------------------------------------------------------------------\n");   
                printf("\t\t\t\t                              Receipt %d\n", r_num);
                printf("\t\t\t\t=====================================================================\n");
                printf("\t\t\t\t%-20s %s\n", "Customer:", ord.name);
                printf("\t\t\t\t%-20s %s\n", "Phone:", ord.phone);
                printf("\t\t\t\t---------------------------------------------------------------------\n");
                printf("\t\t\t\t%-30s %-15s %-7s  %-5s\n", "Item_Name", "Quantity", "Disc", "Price");
                printf("\t\t\t\t---------------------------------------------------------------------\n");
                for (int j = 0; j < ord.itemcount; j++) {
                    printf("\t\t\t\t%-30s %-15d %-5.2f %%  $%-7.2f\n", ord.item[j].pname, ord.item[j].quantity, ord.item[j].discount, ord.item[j].price);
                }

                printf("\t\t\t\t---------------------------------------------------------------------\n");
                printf("\t\t\t\t%-30s %-24d $%-5.2f\n", "Total:", ord.totalitm, ord.total);
                printf("\t\t\t\t%-55s $%-5.2f\n", "Discounted:", ord.discounted);
                printf("\t\t\t\t%-55s %-15s\n", "PaymentMode:", ord.paymentmode);
                printf("\t\t\t\t=====================================================================\n\n");
                printf("\t\t-----------------------------------------------------------------------------------------------------\n");
                found=1;  
                break;
            }
            r_num++;
        }
        fclose(fp);

        //To check for Receipt Existence
        
        if (!found)
        {
            printf("Not existed!\n");
            system("pause");
            break;
        }

        //Ask if user want to search again
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