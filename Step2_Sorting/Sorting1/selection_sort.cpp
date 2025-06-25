#include<bits/stdc++.h>
using namespace std;

void sortIt(vector<int> &arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        int mini = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[mini]) {
                mini = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    sortIt(arr);

    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}