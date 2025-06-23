/*
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int i, string& s) {
    if(i >= s.length()/2) return true;
    if(s[i] != s[s.length()-i-1]) return false;

    return isPalindrome(i+1, s);
}

int main(){
    string s = "ABCCBA";
    cout << isPalindrome(0, s);
    return 0;
}
*/