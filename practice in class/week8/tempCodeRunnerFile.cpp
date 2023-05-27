#include <bits/stdc++.h>
using namespace std;
char X[100];
stack <char> S;
int isPair(char open, char close){
    if(open == '(' && close == ')') return 1;
    if(open == '[' && close == ']') return 1;
    if(open == '{' && close == '}') return 1;
    return 0;
}
int solve(char *X){
    for(int i = 0;i < strlen(X); i++){
        if(X[i] == '(' || X[i] == '[' || X[i] == '{'){
            S.push(X[i]);
        }
        else if(X[i] == ')' || X[i] == ']' || X[i] == '}' ){
            if(S.empty()) return 0;
            else{
                char temp = S.top();
                if(isPair(temp, X[i])) return 1;

            }
        }
    }
    //end for
    if(S.empty()) return 1;
    else return 0;
}
int main(){
    char vl[100];
    cin >> vl;
    int result = solve(vl);
    cout << result;
}