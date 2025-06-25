#include<bits/stdc++.h>
using namespace std;

void recursive_bubble_sort(vector<int> &arr, int range) {
    if(range == 1) return;

    for(int i=0; i<range-1; i++) {
        if(arr[i] > arr[i+1]) swap(arr[i], arr[i+1]);
    }

    recursive_bubble_sort(arr, range-1);
} 

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    recursive_bubble_sort(arr, n);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}