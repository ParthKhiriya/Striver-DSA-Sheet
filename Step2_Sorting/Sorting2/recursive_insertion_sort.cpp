#include<bits/stdc++.h>
using namespace std;

void recursive_insertion_sort(vector<int> &arr, int n, int sel_index) {
    if(sel_index == n) return;
    int i = sel_index;
    while(i > 0) {
        if(arr[i] < arr[i-1]) swap(arr[i], arr[i-1]);
        i--;
    }
    recursive_insertion_sort(arr, n, sel_index+1);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    recursive_insertion_sort(arr, n, 0);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}