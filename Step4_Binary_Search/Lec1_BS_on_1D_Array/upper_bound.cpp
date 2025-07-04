#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans = n-1;

    while(low <= high) {
        int mid = high + (low-high)/2;
        if(arr[mid] > x) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "N : ";
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    int x;
    cout << "X : ";
    cin >> x;

    cout << upperBound(arr, x);

    return 0;
}