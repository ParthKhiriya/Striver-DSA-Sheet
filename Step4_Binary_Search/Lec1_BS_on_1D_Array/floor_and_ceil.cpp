#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int floor = -1;

    while(low <= high) {
        int mid = high + (low-high)/2;
        if(arr[mid] <= x) {
            floor = arr[mid];
            low = mid+1;
        } else {
            high = mid-1;
        }
    }
    return floor;
}

int findCeil(vector<int> &arr, int x) {
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ceil = -1;

    while(low <= high) {
        int mid = high + (low-high)/2;
        if(arr[mid] >= x) {
            ceil = arr[mid];
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    return ceil;
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

    int floor = findFloor(arr, x);
    int ceil = findCeil(arr, x);
    cout << "Floor : " << floor << endl;
    cout << "Ceil : " << ceil << endl;

    return 0;
}