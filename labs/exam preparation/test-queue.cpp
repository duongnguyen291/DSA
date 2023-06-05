#include <bits/stdc++.h> 
using namespace std;
int main(){
    queue <int> myQueue;
    int n;
    do{
        cout << "Enter interger to add my Queue: " << endl;
        cin >> n;
        myQueue.push(n);
    }while(n);
    cout << "My Queue contains: "<< endl;
    while(!myQueue.empty()){
        cout << " " << myQueue.front();
        myQueue.pop();
    }
    return 0;
}