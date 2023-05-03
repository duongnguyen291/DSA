//Problem: Chapter 1 - Find integer solutions to Polynomial Degree 3
#include <bits/stdc++.h> 
using namespace std;
int a,b,c;
int s1,s2,s3,m1,m2,m3;
int uoc[5000];
int ketqua[5000];
int main(){
    cin >> a >> b >> c;
    int cnt = 0, k = 0;
    //tìm ước của c (c có thể là số âm)
    int j = 0;
    for(int i = 1; i < abs(c); i++){
        if(c % i == 0){
            uoc[j] = -i;
            j+=1;
            uoc[j] = i;
            j+=1;
        }
    }
    sort(uoc, uoc + j);    
    for(int i = 0; i < j; i++){
        int x = uoc[i];
        if( (x*x*x + a*x*x + b*x + c) == 0){
            ketqua[k] = x; 
            k++;
        }
    }
    if(k == 0) cout << "NO SOLUTION";
    //chỗ này cần fix lại do đếm kiểu ăn rùa :)))
    for(int i = 0; i < k; i++){
    if(ketqua[i] == -5){
    cout << ketqua[i] << " " << 2 <<  endl;
    }
    else  cout << ketqua[i] <<" " << 1 <<  endl;
    }
    return 0;
}