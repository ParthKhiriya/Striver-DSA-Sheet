#include<bits/stdc++.h>
using namespace std;

string prefixToInfix(string s) {
    stack<string> st;
    int n = s.length();
    int i = n-1;

    while(i >= 0) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        } else {
            string top1 = st.top();
            st.pop();
            string top2 = st.top();
            st.pop();
            string convertedString = '(' + top1 + s[i] + top2 + ')';
            st.push(convertedString);
        }
        i--;
    }
    return st.top();
}

int main () {
    string s = "*+pq-mn";
    cout << prefixToInfix(s);
    return 0;
}