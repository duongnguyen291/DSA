//Permution with condition
#include <bits/stdc++.h>
using namespace std;
int n;
int a[100];
int cnt= 0;
int printsol(){
    //kiem tra thoa man moi in ra
    int check = 1;
    for(int i = 1;i <=n;i++){
        if(a[i] % i !=0&&i%a[i]!=0){ check = 0;}
        check*=check;
    }
    return check;
}
int check(int i, int k){
    //check thêm perfect
    for(int j = 1; j < k ; j++){
        if(a[j] == i) 
            return 0;
    }
    if(k%i == 0 || i%k == 0) return 1;
    else {
        return 0;
    }
}

void Try(int k){
    for(int i = 1; i <= n; i++ ){
        if(check(i,k)){
            a[k] = i;
            if(k == n) cnt++;
            else Try(k+1);
        }
    }
}
int main(){
    cin >> n;
    Try(1);
    cout <<cnt;
    return 0;
}