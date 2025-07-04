#include<bits/stdc++.h>
using namespace std;

void medianSorted(vector<int>& nums1, vector<int> & nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int i = 0;
    int j = 0;
    int size = n+m;
    vector<int> ans;

    while(i<n && j<m) {
        if(nums1[i] < nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
        } else {
            ans.push_back(nums2[j]);
        }
    }
    while(i < n) {
        ans.push_back(nums1[i]);
        i++;
    }
    while(j < m) {
        ans.push_back(nums2[j]);
        j++;
    }

    int x = ans.size();

    if(x%2 == 0) {
        cout << ((ans[x/2 - 1] + ans[x/2])/2.0);
    } else {
        cout << (ans[(x-1)/2.0]);
    }
    // int even1 = x/2 + 1;
    // int even2 = x/2;
    // int odd = (x+1)/2;
    // double medianOdd = ans[odd];
    // double medianEven = (ans[even1]+ans[even2])/2;

    // if(x%2 == 0) cout << medianEven;
    // else cout << medianOdd;
    // cout << odd;
}

int main() {
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    medianSorted(nums1, nums2);
    return 0;
}