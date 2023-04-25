#include <iostream>
#include <string> 

using namespace std;

//Hàm hoán vị vị trí trong chuỗi.
void permutation(char& a, char& b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << "Input N:";
    short n;
    cin >> n;

    string first_number; // Cấu hình đầu tiên
    string last_number; // Cấu hình cuối cùng
    //Sinh cấu hình đầu tiên, cấu hình cuối cùng
    for (int i = 1; i <= n; i++) {
        first_number += char(i + 48);
        last_number += (n - i + 1 + 48);
    }

    cout << first_number << endl;
    while (first_number != last_number) {
        int i = n - 1;// đặt cờ hiệu
        for (i; i >= 0; i--) {
            if (first_number[i] < first_number[i + 1]) {// Tìm vị trí số liền trước dãy giảm dần
                for (int k = n - 1; k > i; k--) { //Tìm số bé nhất ở dãy giảm dần, nhưng phải lớn hơn first_number[i]
                    if (first_number[k] > first_number[i]) {
                        permutation(first_number[i], first_number[k]);
                        int p = n - 1;//Tạo biến đếm từ phải qua trái để sắp xếp dãy giảm dần thành dãy tăng dần
                        for (int j = i + 1; j <= ((n - i) / 2); j++) {// Xét một nửa dãy giảm dần
                            permutation(first_number[j], first_number[p--]);
                        }
                        break;
                    }

                }
                cout << first_number << endl;
                break;
            }

        }
    }

    return 0;
} 