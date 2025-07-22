#include<bits/stdc++.h>
using namespace std;

string postfixToPrefix(string s){
    stack<string> st;
    int i = 0;
    int n = s.size();

    while(i < n) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string convertedString = s[i] + top2 + top1;
            st.push(convertedString);
        }
        i++;
    }

    return st.top();
}

int main () {
    string s = "ab-de+f*/";
    cout << postfixToPrefix(s);
    return 0;
}