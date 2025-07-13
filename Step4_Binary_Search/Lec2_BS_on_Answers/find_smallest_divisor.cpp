#include<bits/stdc++.h>
using namespace std;

int findSum(vector<int> &arr, int divisor) {
    int n = arr.size();
    int sum = 0; 
    for(int i=0; i<n; i++) {
        sum = sum + ceil((double)(arr[i])/(double)(divisor));
    }
    return sum;
}

int smallestDivisor(vector<int> &arr, int threshold) {
    int n = arr.size();
    if(n > threshold) return -1;
    int low = 1;
    int high = *max_element(arr.begin(), arr.end());

    while(low <= high) {
        int mid = low + (high-low)/2;
        int sum = findSum(arr, mid);
        if(sum <= threshold) high = mid-1;
        else low = mid+1;
    }
    
    return low;
}

int main () {
    int n;
    cout << "N : ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int threshold;
    cout << "Threshold : ";
    cin >> threshold;

    cout << "The smallest divisor is : " << smallestDivisor(arr, threshold) << endl;
    return 0;
}