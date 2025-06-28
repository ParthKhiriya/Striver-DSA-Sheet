// 1. Brute Force: Sort the array and print the second last and second element.
// 2. Better Approach

        // #include<bits/stdc++.h>
        // using namespace std;

        // void getElements(vector<int> &arr) {
        //     int n = arr.size();
        //     if(n==0 || n==1) return -1;
        //     int large = INT_MIN, second_large = INT_MIN;
        //     int small = INT_MAX, second_small = INT_MAX;

        //     for(int i=0; i<n; i++) {
        //         large = max(arr[i], large);
        //         small = min(arr[i], small);
        //     }
        //     for(int i=0; i<n; i++) {
        //         if(arr[i] < second_small && arr[i] != small) second_small = arr[i];
        //         if(arr[i] > second_large && arr[i] != large) second_large = arr[i];
        //     }

        //     cout << "Second Smallest: " << second_small << endl;
        //     cout << "Second Largest: " << second_large << endl;
            
        // }

        // int main() {
        //     int n;
        //     cin >> n;
        //     vector<int> arr(n);
        //     for(int i=0; i<n; i++) {
        //         cin >> arr[i];
        //     }
        //     getElements(arr);
        //     return 0;
        // }


// 3. Optimal Approach: 

#include<bits/stdc++.h>
using namespace std;

int getSecondLarge(vector<int> &arr) {
    int n = arr.size();
    if(n==0 || n==1) return -1;
    int large = INT_MIN;
    int second_large = INT_MIN;

    for(int i=0; i<n; i++) {
        if(arr[i] > large) {
            second_large = large;
            large = arr[i];
        }
        else if(arr[i] > second_large && arr[i] != large) {
            second_large = arr[i];
        }
    }

    return second_large;
}

int getSecondSmall(vector<int> &arr) {
    int n = arr.size();
    if(n==0 || n==1) return -1;
    int small = INT_MAX;
    int second_small = INT_MAX;

    for(int i=0; i<n; i++) {
        if(arr[i] < small) {
            second_small = small;
            small = arr[i];
        }
        else if(arr[i] < second_small && arr[i] != small) {
            second_small = arr[i];
        }
    }

    return second_small;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int second_large = getSecondLarge(arr);
    int second_small = getSecondSmall(arr);

    cout << "Second Largest Element: " << second_large << endl;
    cout << "Second Smallest Element: " << second_small << endl;

    return 0;
}