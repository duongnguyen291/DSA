//Problem: Chapter 3 - Evaluate add - mul - parenthesis expression
#include <bits/stdc++.h>
using namespace std;
stack<char> S;
char X[10001];
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
                S.pop();
                if(isPair(temp, X[i]) == 0) return 0;

            }
        }
    }
    //end for
    if(S.empty()) return 1;
    else return 0;
}

int main(){
    cin >> X;
    cout << X;
    cout << solve(X); 
    if(solve(X)){
        for(int i = 0;i < strlen(X) ;i++){
            if()
        }
    }
    else{
        printf("NOT_CORRECT");
    }
    return 0;
}