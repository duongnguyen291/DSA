#include <bits/stdc++.h>


using namespace std;

int n;

//bool check(int *a, int *b){
//    int c = 0;
//    for (int i = 0; i < 26; i++){
//        if ((a[i] ^ b[i]) == 1){
//            c++;
//            if (c >= 2){
//                return false;
//            }
//        }
//    }
//
//    return true;
//}

int main(){
    cin >> n;
    string y;
    int m = 0;
    int** a = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[26];
    }
//    int **b = new int[n];


    for (int i = 0; i < n; i++){
        cin >> y;
        for (int j = 0; j < 26; j++){
            a[i][j] = 0;
        }
        for (int j = 0; j < y.size(); j++){
            a[i][y[j] - 97] = ~(a[i][y[j] - 97]) & 1;
        }
//        for (int j = 0; j < 26; j++){
//            cout << a[i][j] << " ";
//        }
//        cout << endl;


    }

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++){
            int c = 0;
            for (int k = 0; k < 26; k++){
                if ((a[i][k] ^ a[j][k]) == 1){
                    c++;
                    if (c >= 2){
                        break;
                    }
                }
            }
            if (c < 2){
                m++;
            }
        }

    cout << m ;

}