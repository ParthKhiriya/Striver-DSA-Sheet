#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr) {
    int n = arr.size();
    int i = 0;
    for(int j=1; j<n; j++) {
        if(arr[i] != arr[j]) {
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "The number of unique elements in the array is: " << removeDuplicates(arr) ;
    return 0;
}