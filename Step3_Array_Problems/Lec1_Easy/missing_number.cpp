#include<bits/stdc++.h>
using namespace std;

// Optimal Approach 1: Using Formula
    // int findMissing(vector<int> &arr) {
    //     int n = arr.size();
    //     int sumOfNatural = n*(n+1) / 2;
    //     int sum = 0;
    //     for(int i=0; i<n; i++) {
    //         sum = sum + arr[i];
    //     }

    //     return sumOfNatural - sum;
    // }

// Optimal Approach 2: The XOR approach
int findMissing(vector<int> &arr) {
    int n = arr.size();
    int xor1 = 0;
    int xor2 = 0;

    for(int i=0; i<=n; i++) {
        xor1 = xor1 ^ i;
    }

    for(int i=0; i<n; i++) {
        xor2 = xor2 ^ arr[i];
    }

    int missingNumber = xor1 ^ xor2;
    return missingNumber;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << findMissing(arr);
    return 0;
}