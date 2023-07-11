#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
	if(a < b) return a;
	else return b;
}
 
int max(int a, int b){
	if(a < b) return b;
	else return a;
}
int check(int r, int x, int y, int x1, int y1,int x2, int y2){
	int xn = max(min(x1, x2), min(x, max(x1, x2)));
    int yn = max(min(y1, y2), min(y, max(y1, y2)));
    int Dx = xn - x;
    int Dy = yn - y;
    return (Dx * Dx + Dy * Dy) <= r * r;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int x1, x2, y1, y2;
		int x, y, r;
		cin >> x1 >> y1 >> x2 >>y2 >> x >> y >> r;
		cout << check(r,x,y,x1,y1,x2,y2)<<endl;
	}
}