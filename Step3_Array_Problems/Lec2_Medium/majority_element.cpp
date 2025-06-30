#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    int element;

    for(int i=0; i<n; i++) {
        if(count == 0) {
            count = 1;
            element = arr[i];
        } else if(element == arr[i]) count++;
        else count--;
    }

    return element;
}

int main() {
    int n;
    cout << "N : ";
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout<< "Majority element: " << majorityElement(arr);

    return 0;
}