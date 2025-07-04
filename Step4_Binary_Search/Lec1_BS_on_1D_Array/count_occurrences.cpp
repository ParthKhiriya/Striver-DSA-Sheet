#include<bits/stdc++.h>
using namespace std;

int lastOccurrence(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int lastOccurrence = -1;

    while(low <= high) {
        int mid = high + (low-high)/2;
        if(arr[mid] == x) {
            lastOccurrence = mid;
            low = mid+1;
        } else if (arr[mid] > x) {
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return lastOccurrence;
}

int firstOccurrence(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int firstOccurrence = -1;

    while(low <= high) {
        int mid = high + (low-high)/2;
        if(arr[mid] == x) {
            firstOccurrence = mid;
            high = mid-1;
        } else if (arr[mid] < x) {
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return firstOccurrence;
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

    int last = lastOccurrence(arr, x);
    int first = firstOccurrence(arr, x);
    if(first == -1) cout << "Total number of occurrences is 0";
    else cout << "Total number of occurrences : " << last-first+1;

    return 0;
}