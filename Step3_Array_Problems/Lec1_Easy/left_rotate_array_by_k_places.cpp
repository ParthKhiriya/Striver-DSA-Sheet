// Brute Force Approach: 
//      TC: O(N), SC: O(N)

        // #include<bits/stdc++.h>
        // using namespace std;

        // void rotateRight(vector<int> &arr, int k) {
        //     int n = arr.size();
        //     vector<int> temp(n);
        //     for(int i=0; i<n-k-1; i++) {
        //         temp[i] = arr[i+k+1];
        //     }
        //     for(int i=n-k-1; i<n; i++) {
        //         temp[i] = arr[i-k];
        //     }
        //     arr = temp;
        // }

        // void rotateLeft(vector<int> &arr, int k) {
        //     int n = arr.size();
        //     vector<int> temp(n);
        //     for(int i=0; i<n-k; i++) {
        //         temp[i] = arr[i+k];
        //     }
        //     for(int i=n-k; i<n; i++) {
        //         temp[i] = arr[i-k-1];
        //     }
        //     arr = temp;
        // }

        // void rotateArray(vector<int> &arr, string side, int k) {
        //     if(side == "right") {
        //         rotateRight(arr, k);
        //     } else {
        //         rotateLeft(arr, k);
        //     }
        // }

        // int main() {
        //     int n;
        //     cin >> n;

        //     vector<int> arr(n);
        //     for(int i=0; i<n; i++) {
        //         cin >> arr[i];
        //     }

        //     int k;
        //     cout << "What is the value of k ? ";
        //     cin >> k;

        //     string side;
        //     cout << "Which side do you want to rotate the array ? ";
        //     cin >> side;

        //     rotateArray(arr, side, k);

        //     for(int i=0; i<n; i++) {
        //         cout << arr[i] << " ";
        //     }

        //     return 0;
        // }



// Optimal Solution: 

#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int start, int end) {
    while(start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void rotateRight(vector<int> &arr, int k) {
    int n = arr.size();
    reverse(arr, n-k, n-1);
    reverse(arr, 0, n-k-1);
    reverse(arr, 0, n-1);
}

void rotateLeft(vector<int> &arr, int k) {
    int n = arr.size();
    reverse(arr, 0, k-1);
    reverse(arr, k, n-1);
    reverse(arr, 0, n-1);
}

void rotateArray(vector<int> &arr, int k, string side) {
    if(side == "left") {
        rotateLeft(arr, k);
    } else {
        rotateRight(arr, k);
    }
}

int main() {
    int n;
    cout << "The number of elements in the array are: ";
    cin >> n;

    vector<int> arr(n);
    cout << "The elements of the array are: ";

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int k; 
    cout << "The value of k is: ";
    cin >> k;

    string side; 
    cout << "Which side do you want to rotate the array ? ";
    cin >> side;

    rotateArray(arr, k, side);

    cout << "The Rotated Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}