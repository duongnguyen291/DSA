#include <bits/stdc++.h>
using namespace std;
typedef struct bank{
    char fromAccount[21];
    char toAccount[21];
    int money;
    char time[10];
    char atm[11];
}bank;
bank data[1000000];
char sortName[1000000][21];
int totalMoneyTransaction(bank *data,int i){
    int sum = 0;
    for(int j = 0;j < i;j++){
        sum += data[j].money;
    }
    return sum;
}
int totalMoneyForm(bank *data, int i, char name[21]){
    int sum = 0;
    for(int j = 0;j < i;j++){
        if(strcmp(data[j].fromAccount,name) == 0) sum += data[j].money;
    }
    return sum;
}
int inspect_cycle(bank *data, int i, char name[21], int k){
    int check = 0;
    for(int j = 0;j < i;j++){
        if(strcmp(data[j].fromAccount,name) == 0) check++;
    }
    if(check == k) return 1;
    else return 0;
}
int partition(char a[][21], int low, int high){
    char pivot[21];
    strcpy(pivot,a[high]); 
    int i = low-1;
    for(int j=low;j<high;j++){
        if(strcmp(a[j],pivot) <= 0){
            i++;
            char temp[21];
            strcpy(temp,sortName[i]);
            strcpy(sortName[i],sortName[j]);
            strcpy(sortName[j],temp);
            // swap(a[i],a[j]);
        }
    }
    char temp[21];
    strcpy(temp,sortName[i+1]);
    strcpy(sortName[i+1],sortName[high]);
    strcpy(sortName[high],temp);
    // swap(a[i+1],a[high]);
    return i+1;
}
void quickSort(char a[][21], int low, int high){
    if(low < high){
        int pivot = partition(a, low, high);
        quickSort(a,low,pivot-1);
        quickSort(a,pivot+1,high);
    }
} 
void sort(bank *data, int i){
    int j = 0;
    //save the name exist in data to sortName
    for(int k = 0;k < i;k++){
        int check = 0;
        for(int l = 0;l < j;l++){
            if(strcmp(data[k].fromAccount,sortName[l]) == 0) check++;
        }
        if(check == 0){
            strcpy(sortName[j],data[k].fromAccount);
            j++;
        }
    }
    //sort by alphabet order by quicksort
    quickSort(sortName,0,j-1);
    for(int k = 0;k < j;k++){
        cout << sortName[k] << " ";
    }
    cout << endl;
}
 
int main(){
    freopen("test2.txt","r",stdin);
    //nhập dữ liệu vào bank 
    //<from_account>   <to_account>   <money>   <time_point>   <atm>
    //ex:   T000010010 T000010020 1000 10:20:30 ATM1
    char temp[100];
    int i = 0;
    while(true){
        cin >> temp;
        if(strcmp(temp,"#") == 0) break;
        else{
            strcpy(data[i].fromAccount,temp);
            cin >> data[i].toAccount >> data[i].money >> data[i].time >> data[i].atm;
            i++;
        }
    }
    string s;
    while(true){
        cin >> s;
        if(s == "#") break;
        else if(s == "?number_transactions"){
            cout << i << endl;
        }
        else if(s == "?total_money_transaction"){
            int sum = totalMoneyTransaction(data,i);
            cout << sum << endl;
        }
        else if(s == "?total_money_transaction"){
            int sum = totalMoneyTransaction(data,i);
            cout << sum << endl;
        }
        else if(s == "?list_sorted_accounts"){
            sort(data,i);
        }
        else if(s == "?total_money_transaction_from"){
            char temp[21];
            cin >> temp;
            int sum = totalMoneyForm(data,i,temp);
            cout << sum << endl;
        }
        else if(s == "?inspect_cycle"){
            char temp[21];
            int k;
            cin >> temp;
            cin >> k;
            int sum = inspect_cycle(data,i,temp,k);
            cout << sum << endl;
        }
        else {cout << "\nInvalid command\n";}

    }
 
    
}