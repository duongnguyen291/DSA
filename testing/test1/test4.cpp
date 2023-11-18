#include <iostream>
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
    int maxx = 0;
    int temp = 0;
    int p,q;
    for(int i = 0;i < height.size()-1;i++){
        for(int j = i+1;j < height.size();j++){
            temp = abs(i-j)*abs(height[j] - height[i]);
            if(temp > maxx ) {maxx  = temp;p=i;q=j;}
        }
    } 
    cout << p << " " << q << endl;
    return maxx;
}
int main(){
    freopen("test1.txt","r",stdin);
    vector <int> h;
    int n;
    cin >>n;
    int k;
    for(int i=0;i < n;i++){
        cin >> k;
        h.push_back(k);
    }
    int res = maxArea(h); 
    cout << res;
    return 0;
}