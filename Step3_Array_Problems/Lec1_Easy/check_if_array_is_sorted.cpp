#include<bits/stdc++.h>
using namespace std;

bool checkSorted(vector<int> &arr) {
    int n = arr.size();
    if(n < 2) return true;

    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    string ans = checkSorted(arr) ? "True" : "False";

    cout << ans;

    return 0;
}