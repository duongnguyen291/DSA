//Problem: Intersection Rectangle and Circle

#include <bits/stdc++.h>
using namespace std;
int check1(int x1,int y1,int x2,int y2,int x,int y,int r){
	int xn = max(min(x1, x2), min(x, max(x1, x2)));
    int yn = max(min(y1, y2), min(y, max(y1, y2)));
    int Dx = xn - x;
    int Dy = yn - y;
    return (Dx * Dx + Dy * Dy) <= r * r;
}

int main(){
    freopen("test1.txt","r",stdin);
    int n, x1,y1,x2,y2,x,y,r;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> x >> y >> r;
        int temp = check1(x1,y1,x2,y2,x,y,r);
        cout << temp << endl;
    }
    return 0;
}
/*
Input
2
0 0 4 2
2 3 2
0 0 3 3
10 10 1

Output 
1
0*/