#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = high + (low-high)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] > x) high = mid-1;
        else low = mid+1;
    }
    return -1;
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

    cout << binarySearch(arr, x);

    return 0;
}