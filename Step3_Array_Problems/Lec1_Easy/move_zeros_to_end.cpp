#include<bits/stdc++.h>
using namespace std;

void moveZeros(vector<int> &arr) {
    int n = arr.size();
    int j = -1;

    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            j = i;
            break;
        }
    }

    if(j == -1) return;

    for(int i=j+1; i<n; i++) {
        if(arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
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

    moveZeros(arr);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}