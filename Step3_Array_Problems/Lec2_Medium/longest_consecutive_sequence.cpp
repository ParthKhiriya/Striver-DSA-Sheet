#include<bits/stdc++.h>
using namespace std;

// The below is a good approach but not optimal: 

        // int longestSequence(vector<int> &arr) {
        //     int n = arr.size();
        //     sort(arr.begin(), arr.end());
        //     int lastSmallest = INT_MIN;
        //     int count = 0;
        //     int longest = 1;

        //     for(int i=0; i<n; i++) {
        //         if(arr[i]-1 == lastSmallest) {
        //             count++;
        //             lastSmallest = arr[i];
        //         } else if(arr[i] != lastSmallest) {
        //             lastSmallest = arr[i];
        //             count = 1;
        //         }
        //         longest = max(longest, count);
        //     }

        //     return longest;
        // }


// Optimal Approach : Using the Set Data structure
int longestSequence(vector<int> &arr) {
    int n = arr.size();
    int count = 0;
    int longest = 1;
    unordered_set<int> st;

    for(int i=0; i<n; i++) {
        st.insert(arr[i]);
    }

    for(auto it: st) {
        if(st.find(it-1) == st.end()) {
            int x = it;
            int count = 1;

            while(st.find(x+1) != st.end()) {
                x = x + 1;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}

int main() {
    int n;
    cout << "N : ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "The length of the longest consecutive subsequence is : " << longestSequence(arr);

    return 0;
}