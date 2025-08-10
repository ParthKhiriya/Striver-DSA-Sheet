// Brute Force Approach :

// #include<bits/stdc++.h>
// using namespace std;

// int largestRectangle(vector<int> &arr) {
//     int n = arr.size();
//     int maxArea = 0;

//     for(int i=0; i<n; i++) {
//         int minHeight = INT_MAX;
//         for(int j=i; j<n; j++) {
//             minHeight = min(minHeight, arr[j]);
//             maxArea = max(maxArea, minHeight*(j-i+1));
//         }
//     }
//     return maxArea;
// }

// int main () {
//     vector<int> arr = {2, 1, 5, 6, 2, 3, 1};
//     cout << "The Largest area in the given histogram is : " << largestRectangle(arr) << endl;
//     return 0;
// }


