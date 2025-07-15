#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>> &mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = (n*m) - 1;

    while(low <= high) {
        int mid = low + (high-low)/2;
        int row = mid / m;
        int col = mid % m;

        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid+1;
        else high = mid-1; 
    }

    return false;
}

int main () {

    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 13}};

    int n = mat.size();
    int m = mat[0].size();

    int target;
    cout << "Target : ";
    cin >> target;

    binarySearch(mat, target) == true ? cout<<"True" : cout<<"False";

    return 0;
}