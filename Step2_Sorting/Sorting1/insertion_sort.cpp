#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        int j = i;
        while(j > 0) {
            if(arr[j-1] > arr[j]) swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    insertion_sort(arr);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}