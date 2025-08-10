// This is the Brute Force Approach to solve this question.

// #include<bits/stdc++.h>
// using namespace std;

// int trap(vector<int>& arr) {
//     int n = arr.size();
//     int trap = 0;

//     for(int i=0; i<n; i++) {
//         int j = i;
//         int leftMax = 0;
//         int rightMax = 0;

//         while(j >= 0) {
//             leftMax = max(leftMax, arr[j]);
//             j--;
//         }

//         j = i;

//         while(j < n) {
//             rightMax = max(rightMax, arr[j]);
//             j++;
//         }

//         trap = trap + min(leftMax, rightMax) - arr[i];
//     }

//     return trap;
// }

// int main () {
//     vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
//     cout << "The water that can be trapped is : " << trap(arr) << endl;
//     return 0;
// }


// Better Approach: 

// #include<bits/stdc++.h>
// using namespace std;

// int trap(vector<int> &arr) {
//     int n = arr.size();
//     int trap = 0;
//     int prefix[n];
//     int suffix[n];

//     prefix[0] = arr[0];
//     for(int i=0; i<n; i++) {
//         prefix[i] = max(prefix[i-1], arr[i]);
//     }

//     suffix[n-1] = arr[n-1];
//     for(int i=n-2; i>=0; i--) {
//         suffix[i] = max(suffix[i+1], arr[i]);
//     }

//     for(int i=0; i<n; i++) {
//         trap = trap + min(prefix[i], suffix[i]) - arr[i];
//     }

//     return trap;
// }

// int main () {
//     vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
//     cout << "The water that can be trapped is: " << trap(arr) << endl;
//     return 0;
// }


// Optimal Approach : Two pointer approach --

#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr) {
    int n = arr.size();
    int left = 0;
    int right = n-1;
    int leftMax = 0, rightMax = 0;
    int result = 0;

    while(left <= right) {
        if(arr[left] <= arr[right]) {
            if(leftMax <= arr[left]) leftMax = arr[left];
            else result += leftMax - arr[left];
            left++;
        } else {
            if(rightMax <= arr[right]) rightMax = arr[right];
            else result += rightMax - arr[right];
            right--;
        }
    }

    return result;
}

int main () {
    vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The water that can be trapped is : " << trap(arr) << endl;
    return 0;
}