#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(vector<int> &arr) {
    int n = arr.size();
    int sum = 0;
    int maxi = INT_MIN;

    for(int i=0; i<n; i++) {
        sum = sum + arr[i];
        if(sum > maxi) maxi = sum;
        if(sum < 0) sum = 0;
    }

    return maxi;
}

int main() {
    int n;
    cout << "N : ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout<< "The maximum subarray sum is: " << maxSubarraySum(arr);

    return 0;
}