#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc dữ liệu cho sản phẩm
typedef struct Item {
    char ID[12];
    int quantity;
    char insertDate[21];
    double price;
    struct Item* next;
} Item;

// Hàm để thêm một sản phẩm vào giỏ hàng
void addItem(Item** head, char ID[], int quantity, char insertDate[], double price) {
    Item* newItem = (Item*)malloc(sizeof(Item));
    strcpy(newItem->ID, ID);
    newItem->quantity = quantity;
    strcpy(newItem->insertDate, insertDate);
    newItem->price = price;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    }
    else {
        Item* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newItem;
    }
}

// Hàm để đọc thông tin các sản phẩm input
void readItemList(Item** head) {
    char ID[12];
    int quantity;
    char insertDate[21];
    char nextLine[100];
    double price;
    int count = 0;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);
        if (strlen(ID) == 0) continue;
        if (strcmp(ID, "-1") == 0) {
            break;
        }

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%d", &quantity);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        strcpy(insertDate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%lf", &price);

        count++;
        addItem(head, ID, quantity, insertDate, price);
    }
    printf("Total: %d\n", count);
}
/////////////////////////////////////////////////////////////////////////////////
// PHẦN CODE LÀM CỦA SINH VIÊN
//////////////////////////////////////////////////
Item *findanItemByID(Item *head, char ID[]){
    if(head == NULL) return NULL;
    Item *temp = head;
    while(temp != NULL){
        if(strcmp(temp->ID,ID) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}
double checkCartTotalPrice(Item *head){
    double total = 0;
    Item *temp = head;
    while(temp !=NULL){
        total += temp->price * temp->quantity;
        temp = temp ->next;
    }
    return total;
}
int reduceItemQuantityByID(Item **head,char ID[],int n){
    if(*head == NULL) return 0;
    Item *p = *head;
    if(strcmp(p->ID,ID) == 0){
        *head = p->next;
        return 1;
    }
    Item *check = *head;
    Item *temp = findanItemByID(check,ID);
    if(temp == NULL) return 0;
    if(temp->quantity > n){
        temp->quantity = temp->quantity - n;
        return 1;
    }
    else{
        Item *cur = *head;
        while(cur->next!=temp) cur = cur->next;
        cur->next = temp->next;
        delete temp;
        return 1;
    }

}
void addNewItem(Item **head,char ID[],int quantity, char insertDate[], double price){
    Item *p = *head;
    Item *temp = findanItemByID(p, ID);
    if(temp == NULL){
        Item *newItem = new Item();
        addItem(head, ID,quantity,insertDate,price);
    }
    else{
        temp->quantity +=quantity;
    }
}

///////////////////////////////////////////////////
// HẾT PHẦN LÀM CỦA SINH VIÊN
////////////////////////////////////////////////////////////////////////////////

void findItemsByID(Item* head)
{
    char ID[11], nextLine[100];;
    Item* anItem = NULL;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);

        if (strcmp(ID, "-1") == 0) {
            break;
        }
        anItem = findanItemByID(head, ID);
        if (anItem == NULL) printf("Item NOT FOUND\n");
        else printf("Item's already added at %s\n", anItem->insertDate);
    }
}




void reduceItemQuantityByIDs(Item** head)
{
    char ID[12], nextLine[100];
    int reduceQuantity;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s %d", ID, &reduceQuantity);
        if (strcmp(ID, "-1") == 0) {
            break;
        }
        if (reduceItemQuantityByID(head, ID, reduceQuantity))
            printf("DONE Remove\n");
        else
            printf("ID NOT FOUND\n");
    }
}




// Hàm để đọc thông tin các sản phẩm input
void addNewItems(Item** head) {
    char ID[12];
    int quantity;
    char insertDate[21];
    char nextLine[100];
    double price;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);
        if (strlen(ID) == 0) continue;
        if (strcmp(ID, "-1") == 0) {
            break;
        }

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%d", &quantity);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        strcpy(insertDate, nextLine);

        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%lf", &price);

        addNewItem(head, ID, quantity, insertDate, price);
    }
}
// Hàm để test các hàm đã định nghĩa ở trên

int main() {
    Item* cartList = NULL;
    char nextCommand[100];
    while (1)
    {
        fgets(nextCommand, sizeof(nextCommand), stdin);
        nextCommand[strcspn(nextCommand, "\r\n")] = 0;
        if (nextCommand[0] != '?') break;
        if (strcmp(&nextCommand[2], "readCart") == 0)
            readItemList(&cartList);
        else if (strcmp(&nextCommand[2], "findItemsByID") == 0)
            findItemsByID(cartList);
        else if (strcmp(&nextCommand[2], "reduceItemQuantityByIDs") == 0)
            reduceItemQuantityByIDs(&cartList);
        else if (strcmp(&nextCommand[2], "addNewItems") == 0)
            addNewItems(&cartList);
        else if (strcmp(&nextCommand[2], "checkCartTotalPrice") == 0)
            printf("Total price: %.2lf\n", checkCartTotalPrice(cartList));
    }

    return 0;
}
