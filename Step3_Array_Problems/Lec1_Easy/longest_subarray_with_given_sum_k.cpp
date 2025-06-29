#include<bits/stdc++.h>
using namespace std;

// The below is an Optimal Approach when the array only contains Positive Elemenets:
    int lengthOfLongestSubarray(vector<int> &arr, int k) {
        int n = arr.size();
        int left = 0;
        int right = 0;
        int sum = arr[0];
        int maxLen = 0;

        while(right < n) {
            while(left <= right && sum > k) {
                sum = sum - arr[left];
                left++;
            }
            if(sum == k) maxLen = max(maxLen, right-left+1);

            right++;
            if(right < n) sum += arr[right];
        }

        return maxLen;
    }

// The below is an Optimal Approac when the array contains both Positive and Negative elements:


int main () {
    int n; 
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << lengthOfLongestSubarray(arr, k);
    return 0;
}