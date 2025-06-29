#include<bits/stdc++.h>
using namespace std;

// Using Set:
    // vector<int> findUnion(vector<int> &arr1, vector<int> &arr2) {
    //     int n = arr1.size();
    //     int m = arr2.size();
    //     set<int> s;
    //     vector<int> UnionArray;

    //     for(int i=0; i<n; i++) {
    //         s.insert(arr1[i]);
    //     }
    //     for(int j=0; j<m; j++) {
    //         s.insert(arr2[j]);
    //     }
    //     for(auto &it: s) {
    //         UnionArray.push_back(it);
    //     }

    //     return UnionArray;
    // }

// Using Two pointers: Optimal Approach
vector<int> findUnion(vector<int> &arr1, vector<int> &arr2) {
    int n = arr1.size();
    int m = arr2.size();
    vector<int> UnionArray;

    int i = 0;
    int j = 0;

    while(i < n && j < m) {
        if(arr1[i] <= arr2[j]) {
            if(UnionArray.size() == 0 || UnionArray.back() != arr1[i]) UnionArray.push_back(arr1[i]);
            i++;
        } else {
            if(UnionArray.size() == 0 || UnionArray.back() != arr2[j]) UnionArray.push_back(arr2[j]);
            j++;
        }
    }

    while(i < n) {
        if(UnionArray.back() != arr1[i]) UnionArray.push_back(arr1[i]);
        i++;
    }

    while(j < m) {
        if(UnionArray.back() != arr2[j]) UnionArray.push_back(arr2[j]);
        j++;
    }

    return UnionArray;
} 

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    vector<int> arr2(m);
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }
    vector<int> UnionArray = findUnion(arr1, arr2);

    for(int i=0; i<UnionArray.size(); i++) {
        cout << UnionArray[i] << " ";
    }
    return 0;
}