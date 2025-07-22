#include<bits/stdc++.h>
using namespace std;

int priority(char ch) {
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    return 0;
}

string infixToPostfix(string s) {
    int n = s.length();
    int i = 0;
    stack<char> st;
    string ans = "";

    while(i < n) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
            ans = ans + s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                ans = ans + st.top();
                st.pop();
            }
            st.pop();
        } else {
            while(!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans = ans + st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while(!st.empty()) {
        ans = ans + st.top();
        st.pop();
    }

    return ans;
}

int main () {
    string s = "a+b*(c^d-e)";
    string ans = infixToPostfix(s);
    cout << ans;
    return 0;
}