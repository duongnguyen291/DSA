#include <bits/stdc++.h>
using namespace std;

typedef struct library {
    char id[10];
    char book[20];
    char day[15];
} library;

typedef struct numberBook {
    char book[20];
    int count;
} numberBook;

library data[101];
numberBook books[101];
bool compareBooks(const numberBook& a, const numberBook& b) {
    if (a.count == b.count) {
        return strcmp(a.book, b.book) < 0;
    }
    return a.count > b.count;
}
void printBookCount(numberBook books[], int count) {
    sort(books, books + count, compareBooks);
    for (int i = 0; i < count; i++) {
        cout << books[i].book << " " << books[i].count << endl;
    }
}

int main() {
    int i = 0;
    freopen("test2.txt", "r", stdin);
    do {
        scanf("%s %s %s", data[i].id, data[i].book, data[i].day);
        i++;
    } while (strcmp(data[i-1].id, "*") != 0);

    int bookCount = 0;
    for (int j = 0; j < i-1; j++) {
        int found = 0;
        for (int k = 0; k < bookCount; k++) {
            if (strcmp(books[k].book, data[j].book) == 0) {
                found = 1;
                books[k].count++;
                break;
            }
        }
        if (found!=1) {
            strcpy(books[bookCount].book, data[j].book);
            books[bookCount].count = 1;
            bookCount++;
        }
    }
    // cout << bookCount << endl;
    printBookCount(books, bookCount );

    return 0;
}
