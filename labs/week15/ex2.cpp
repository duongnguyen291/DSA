            test.push_back(s);
//bài luyện trên lớp
#include <iostream>
#include <vector>
using namespace std;
void heapify(vector<string>& a, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(vector<string>& a, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}


int main() {
    vector<string> test;
    string s;
    freopen("test2.txt","r",stdin);
    while(1){
        // cin >> s;
        getline(cin,s);
        // cout << s << "\n"; //Note: dùng như này sẽ lỗi , thay vì nhận "Nguyen Dinh Duong " là 1 vào vecto
        //thì sẽ nhận thành "Nguyen","Dinh","Duong"
        // cout << test.size();
        if(s == "#") break;
        else{
        }
    }
    int n = test.size(); //số lượng phần tử của vecto
    heapSort(test,n);
    //in phần tử vecto đã được sắp xếp
    for (int i = 0; i < n; i++){
        cout << test[i] << "\n";
    }
    return 0;
}
