#include<bits/stdc++.h>
using namespace std;

// The below approach is only applicable when there are equal positive and negative elements in the array, if the elements are not balanced, then we have to use brute force approach of creating positive and negative arrays.
vector<int> rearrangeBySign(vector<int> &arr) {
    int n = arr.size();
    int posIndex = 0;
    int negIndex = 1;
    vector<int> ans(n, 0);

    for(int i=0; i<n; i++) {
        if(arr[i] < 0) {
            ans[negIndex] = arr[i];
            negIndex += 2;
        } else {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "N : ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    vector<int> ans = rearrangeBySign(arr);

    for(int i=0; i<n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}