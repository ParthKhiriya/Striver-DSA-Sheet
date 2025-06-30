#include<bits/stdc++.h>
using namespace std;

// This is the optimal approach to solve this question
// TC: O(N)
// SC: O(1)
void sortColors(vector<int> &arr) {
    int n = arr.size();
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid <= high) {
        if(arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n; 
    cout << "N : ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    sortColors(arr);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
}