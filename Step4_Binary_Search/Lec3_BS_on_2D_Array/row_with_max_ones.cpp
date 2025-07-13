#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int x) {
    int n = arr.size();
    int ans = n;
    int low = 0;
    int high = n-1;

    while(low <= high) {
        int mid = low + (high-low)/2;
        if(arr[mid] >= x) {
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }

    return ans;
}

int rowWithMaxOnes(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int maxCount = 0;
    int index = -1;

    for(int i=0; i<n; i++) {
        int ones = m - lowerBound(mat[i], 1);
        if(ones > maxCount) {
            maxCount = ones;
            index = i;
        }
    }

    return index;
}

int main () {
    vector<vector<int>> mat = {{1, 1, 0}, {1, 1, 1}, {0, 0, 0}};
    int n = mat.size();
    int m = mat[0].size();

    cout << n << m << endl;
    cout << "Row with maximum number of ones is : " << rowWithMaxOnes(mat);

    return 0;
}