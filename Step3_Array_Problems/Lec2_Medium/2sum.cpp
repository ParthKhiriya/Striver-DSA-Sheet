#include<bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target) {
    int n = arr.size();
    unordered_map<int, int> mpp;

    for(int i=0; i<n; i++) {
        int nums = arr[i];
        int moreNeeded = target - nums;
        if(mpp.find(moreNeeded) != mpp.end()) return {mpp[moreNeeded], i};
        mpp[nums] = i;
    }
    return {-1, -1};
}

int main() {
    int n;
    cout << "n: ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Target: ";
    cin >> target;

    vector<int> ans = twoSum(arr, target);

    for(int i=0; i<2; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}