/*The Tower of Hanoi, consists of three towers (a), (b), (c) together with n disks of 
different sizes. Initially these disks are stacked on the tower (a) in an ascendingorder, 
i.e. the smaller one sits over the larger one.The objective of the game is to move all the 
disks from tower (a) to tower (c), following 3 rules: 
• Only one disk can be moved at a time. 
• Only the top disk can be moved
• No large disk can be sit over a smaller disk.
Let h_n denote the minimum number of moves needed to solve the Tower of Hanoi 
problem with n disks. What is the recurrence relation*/
#include <bits/stdc++.h>
using namespace std;
int hanoiTower(int n,int a,int c,int b){
    if(n == 1) return 1;
    else{
        hanoiTower(n - 1,a,b,c);
        hanoiTower(1,a,c,b);
        hanoiTower(n-1,b,c,a);
    }
}
int main(){
    int n,a,c,b;

    return 0;
}