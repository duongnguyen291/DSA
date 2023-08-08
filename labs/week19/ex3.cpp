#include <bits/stdc++.h>
using namespace std;
double space(int x1, int x2, int y1, int y2){
    int x = abs(x1-x2);
    int y = abs(y1-y2);
    return sqrt(x*x + y*y);
}

int check(int x1, int x2, int y1, int y2,int x, int y, int r){
    int x3,y3;
    //tìm điểm gần đường tròn nhất
    if(x1<= x&&x<= x2 || x2<=x&&x<=x1) x3 = x;
        else{ x3 = abs(x-x1) < abs(x-x2) ? x1:x2;}
    if(y1<= y&&y<= y2 || y2<=y&&y<=y1) y3 = y;
        else {y3 = abs(y-y1) < abs(y-y2) ? y1:y2 ;}
    //so sánh khoảng cách
    // cout << "Space: " << space(x3,x,y3,y) <<endl;
    return space(x3,x,y3,y) <= r ? 1 : 0;

}
int main(){
    int n,x1,x2,y1,y2,x,y,r;
    freopen("test2.txt","r",stdin);
    scanf("%d\n",&n);
    for(int i = 0;i < n;i++){
        scanf("%d %d %d %d\n",&x1,&y1,&x2,&y2);
        scanf("%d %d %d",&x,&y,&r);
        int temp = check(x1,x2,y1,y2,x,y,r);
        printf("%d\n",temp);
    } 
}