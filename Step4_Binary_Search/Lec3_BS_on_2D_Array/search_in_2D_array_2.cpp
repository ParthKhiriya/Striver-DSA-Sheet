#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>> &mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int row = 0;
    int col = m-1;

    while(row<n && col>=0) {
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) row++;
        else col--; 
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