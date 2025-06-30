#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &arr) {
    int n = arr.size();
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int i=0; i<n; i++) {
        minPrice = min(minPrice, arr[i]);
        maxProfit = max(maxProfit, arr[i]-minPrice);
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "N : ";
    cin >> n;
    
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    cout << "The maximum profit which you can make is : " << maxProfit(arr);
    return 0;
}