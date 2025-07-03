#include<bits/stdc++.h>
using namespace std;

// This is a good approach but not optimal for this question:

    // void setZero(vector<vector<int>>& mat) {
    //     int n = mat.size();
    //     int m = mat[0].size();

    //     int row[n] = {0};
    //     int col[m] = {0};

    //     for(int i=0; i<n; i++) {
    //         for(int j=0; j<n; i++) {
    //             if(mat[i][j] == 0) {
    //                 row[i] = 1;
    //                 col[j] = 1;
    //             }
    //         }
    //     }

    //     for(int i=0; i<n; i++) {
    //         for(int j=0; j<n; j++) {
    //             if(row[i] || col[j]) {
    //                 mat[i][j] = 0;
    //             }
    //         }
    //     }
    // }


void setZero(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    int col0 = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(mat[i][j] == 0) {
                mat[i][0] = 0;
                if(j != 0) mat[0][j] = 0;
                else col0 = 0;
            }
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(mat[i][j] != 0) {
                if(mat[i][0] == 0 || mat[0][j] == 0) mat[i][j] = 0;
            }
        }
    }

    if(mat[0][0] == 0) for(int j=0; j<m; j++) mat[0][j] = 0;
    if(col0 = 0) for(int i=0; i<n; i++) mat[i][0] = 0;

}

int main() {
    vector<vector<int>> mat = {{1,1,1},{1,0,1},{1,1,1}};
    int n = mat.size();
    int m = mat[0].size();

    setZero(mat);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}