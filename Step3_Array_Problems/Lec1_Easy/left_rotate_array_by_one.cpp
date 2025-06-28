#include<bits/stdc++.h>
using namespace std;

void leftRotate(vector<int> &arr) {
    int n = arr.size();
    int temp = arr[0];
    for(int i=0; i<n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    leftRotate(arr);
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

// TC: O(N)
// SC: O(1)
// If we used the Brute force approach, in which we create an extra temp array, the space complexity would be O(N), but here we are just doing by using a single temp variable, so this approach is optimal.