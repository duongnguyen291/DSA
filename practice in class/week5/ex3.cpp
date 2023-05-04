//học khai báo linked list trong C
#include <bits/stdc++.h>
using namespace std;
struct data{
    char studentID[8];
    double math, physics;
};
struct Node{
    struct data a;
    struct Node *next;
};
int main(){
    struct Node *newNode = (Node *) malloc(sizeof(Node));

    return 0;
}