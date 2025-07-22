#include<bits/stdc++.h>
using namespace std;

string postfixToInfix(string s) {
    int n = s.length();
    int i = 0;
    stack<string> st;

    while(i < n) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string convertedString = '(' + top2 + s[i] + top1 + ')';
            st.push(convertedString);
        }
        i++;
    }

    return st.top();
}

int main() {
    string s = "ab-de+f*/";
    cout << postfixToInfix(s);
    return 0;
}