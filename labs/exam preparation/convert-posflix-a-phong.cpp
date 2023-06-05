#include <bits/stdc++.h>
using namespace std;
int check(char c){
    if(c=='+' || c=='-' || c =='*' ||c == '/'){
        return 1;
    }
    else
        if(c=='('|| c ==')' )
            return 2;
    else{
        return 3;
    }
}

int precedence(char ch) {
if(ch == '^')
    return 3;
if(ch == '/' || ch =='*')
    return 2;
else if(ch == '+' || ch == '-')
    return 1;
else
    return -1;
}
string Postfix(string s)
{
    stack<char> st;
    string postfix_exp;

    for(int i = 0; i < s.length(); i++)
    {
    char ch = s[i];

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    postfix_exp += ch;

    else if(ch == '(')
    st.push('(');
    else if(ch == ')') {
    while(st.top() != '('){
        postfix_exp += st.top();
        st.pop();
    }
    st.pop();
}
    else
    {
    while(!st.empty() && precedence(s[i]) <= precedence(st.top())) {
        postfix_exp += st.top();
        st.pop();
    }
        st.push(ch);
    }
}
    while(!st.empty()) {
        postfix_exp += st.top();
        st.pop();
    }
    return postfix_exp;
}
string preprocess(string s){
    string news;
    for(int i=0;i<s.length();i++){
        if(check(s[i]) == 3 && check(s[i+1]) != 3){
            news = news + s[i];
        }
        else if(i == s.length()-1 && check(s[i] == 3)){
            news += s[i];
        }
        else if(check(s[i]) != 3){
            news = news + s[i];
        }
    }
    return news;
}
double ans(string s, int array[], int n){
    stack<double> answer;
    int count = 0;
    for(int i=0; i<s.length() ; i++){
        if(check(s[i]) == 3){
            answer.push(array[count]);
            count++;
        }
        else{
            double tmp1;
            tmp1 = answer.top();
            answer.pop();
            double tmp2 = answer.top();
            answer.pop();
            if(s[i] == '+')
                answer.push(tmp1 +tmp2);
            if(s[i] == '-')
                answer.push(tmp2-tmp1);
            if(s[i] == '*')
                answer.push(tmp2*tmp1);
            if(s[i] == '/')
                answer.push((double)tmp2/tmp1);

        }
    }
    return answer.top();
}
int main()
{
    string s;
    cin >> s;
    string news;
    for(int i=0;i<s.length();i++){
        if(check(s[i]) == 3 && check(s[i+1]) != 3){
            news = news + s[i];
        }
    }
    string a[100];
    int c=0;
    for(int i=0;i<s.length();i++){
        if(s[i]>=48&&s[i]<=57){
            a[c]=a[c]+s[i];
        }
        if(check(s[i])==1){
            c++;
        }
    }
    string s1 = preprocess(s);
    string s2 = Postfix(s1);
    c=0;
    for(int i=0;i<s2.length();i++){
        if(s2[i]<='9'&&s2[i]>='0'){
            cout<<a[c]<<" ";
            c++;
        }
        else cout<<s2[i]<<" ";
    }
}
