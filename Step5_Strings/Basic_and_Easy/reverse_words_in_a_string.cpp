#include<bits/stdc++.h>
using namespace std;

int main () {
    string s = "My name is Parth Khiriya";
    s+=" "; // This is necessary as we will push words into the stack when we encounter a space, so a space at the end is necessary to push the last word into the stack.
    stack<string> st;
    string str = "";

    for(int i=0; i<s.length(); i++) {
        if(s[i] == ' ') {
            st.push(str);
            str = "";
        } else {
            str += s[i];
        }
    }

    string ans = "";

    while(st.size() != 1) {
        ans += st.top() + ' ';
        st.pop();
    }
    ans += st.top();
    cout << ans;
    return 0;
}