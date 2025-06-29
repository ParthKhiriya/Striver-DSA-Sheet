#include<bits/stdc++.h>
using namespace std;

int numberAppearingOnce(vector<int> &arr) {
    int n = arr.size();
    int ans = 0;
    for(int i=0; i<n; i++) {
        ans = ans ^ arr[i];
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << numberAppearingOnce(arr);

    return 0;
}