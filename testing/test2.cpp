#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo cấu trúc dữ liệu cho sản phẩm
typedef struct node{
    char ID[12];
    int quantity;
    char insertDate[21];
    double price;
    struct node* next;
}node;

// Hàm để thêm một sản phẩm vào giỏ hàng
void addNode(node **head, char ID[], int quantity, char insertDate[], double price) {
    node* p = (node*)malloc(sizeof(node));
    strcpy(p->ID, ID);
    strcpy(p->insertDate, insertDate);
    p->quantity = quantity;
    p->price = price;
    p->next = NULL;
    if (*head == NULL) {
        *head = p;
    }
    else if(*head!=NULL){
        node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

// Hàm để đọc thông tin các sản phẩm input
void readItemList(node** head) {
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
        addNode(head, ID, quantity, insertDate, price);
    }
    printf("Total: %d\n", count);
}

// Hàm để tìm kiếm sản phẩm theo mã ID
// Trả về NULL nếu không tìm thấy
// ngược lại trả về địa chỉ của phần tử chứa ID
node* findanItemByID(node* head, char ID[]){
    node* p = head;
    while (p != NULL) {
        if (strcmp(p->ID, ID) == 0) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void findItemsByID(node* head)
{
    char ID[11], nextLine[100];;
    node* anItem = NULL;
    while (1) {
        fgets(nextLine, sizeof(nextLine), stdin);
        nextLine[strcspn(nextLine, "\r\n")] = 0;
        sscanf(nextLine, "%s", ID);

        if (strcmp(ID, "-1") == 0) {
            break;
        }
        anItem = findanItemByID(head, ID);
        if (anItem == NULL) printf("Item NOT FOUND\n");a
        else printf("Item's already added at %s\n", anItem->insertDate);
    }
}


// Hàm tính tổng tiền sản phẩm trong giỏ hàng
double checkCartTotalPrice(node* head) {
    double total = 0;
    node* p = head;

    while (p != NULL) {
        total = total + p->price * p->quantity;
        p = p->next;
    }
    return total;
}

// Hàm giảm số lượng 1 mã sản phẩm
// Nếu số lượng sản phẩm trong giỏ hàng ít hơn hoặc bằng số lượng cần giảm
// thì xóa sản phẩm đó khỏi giỏ hàng
// hàm trả về 1 nếu điều chỉnh thành công và 0 nếu không thành công (ID không tìm thấy)
int reduceItemQuantityByID(node** head, char ID[], int reduceQuantity) {
    node* current = *head;
    node* prev = NULL;
    while (current != NULL) {
        if (strcmp(current->ID, ID) == 0) {
            if (current->quantity > reduceQuantity)
            {
                current->quantity = current->quantity - reduceQuantity;
                return 1;
            }               
            if (prev == NULL) {
                // Xóa phần tử đầu danh sách
                *head = current->next;
            }
            else {
                prev->next = current->next;
            }

            // Giải phóng bộ nhớ của xe bị xóa
            free(current);
            return 1;
        }

        prev = current;
        current = current->next;
    }

    return 0;
}

void reduceItemQuantityByIDs(node** head)
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

// Hàm để thêm một sản phẩm vào giỏ hàng,
// nếu đã có thì tăng số lượng lên
// nếu chưa có thì thêm vào cuối danh sách
void addNewItem(node** head, char ID[], int quantity, char insertDate[], double price) {
    node* anItem = findanItemByID(*head, ID);
    if (anItem == NULL)
    {
        node* newItem = (node*)malloc(sizeof(node));
        strcpy(newItem->ID, ID);
        newItem->quantity = quantity;
        strcpy(newItem->insertDate, insertDate);
        newItem->price = price;
        newItem->next = NULL;

        if (*head == NULL) {
            *head = newItem;
        }
        else {
            node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newItem;
        }
    }
    else
    {
        anItem->quantity = anItem->quantity + quantity;
    }
    
}

// Hàm để đọc thông tin các sản phẩm input
void addNewItems(node** head) {
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
    node* cartList = NULL;
    char nextCommand[100];
    freopen("test1.txt", "r", stdin);
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