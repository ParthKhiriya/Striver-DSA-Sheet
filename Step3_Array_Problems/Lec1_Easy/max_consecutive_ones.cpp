#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    int maxCount = 0;

    for(int i=0; i<n; i++) {
        if(arr[i] == 1) count ++;
        else count = 0;
        maxCount = max(maxCount, count);
    }

    return maxCount;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << maxConsecutiveOnes(arr);

    return 0;
}