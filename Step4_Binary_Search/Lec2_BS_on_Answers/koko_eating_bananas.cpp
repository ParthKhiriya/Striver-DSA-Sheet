// Brute Force Approach : 
        
        // #include<bits/stdc++.h>
        // using namespace std;

        // int findMax(vector<int> &piles) {
        //     int maxi = INT_MIN;
        //     int n = piles.size();
        //     for(int i=0; i<n; i++) {
        //         maxi = max(piles[i], maxi);
        //     }
        //     return maxi;
        // }

        // int minTimeRequired(vector<int> &piles, int perHour) {
        //     int totalHours = 0;
        //     int n = piles.size();
        //     for(int i=0; i<n; i++) {
        //         totalHours = totalHours + ceil((double)(piles[i])/(double)(perHour));
        //     }
        //     return totalHours;
        // }

        // int minBananasPerHour(vector<int> &piles, int h) {
        //     int n = piles.size();
        //     int maxi = findMax(piles);

        //     for(int i=1; i<=maxi; i++) {
        //         int reqTime = minTimeRequired(piles, i);
        //         if(reqTime <= h) return i;
        //     }
        //     return maxi;
        // }

        // int main () {
        //     int n;
        //     cout << "N : ";
        //     cin >> n;

        //     vector<int> piles(n);
        //     for(int i=0; i<n; i++) {
        //         cin >> piles[i];
        //     }

        //     int h;
        //     cout << "H : ";
        //     cin >> h;

        //     int ans = minBananasPerHour(piles, h);
        //     cout << "The monkey should atleast eat " << ans << " bananas per hour." << endl;
        // }


    

// Optimal Approach using Binary Search : 

#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> &piles) {
    int maxi = INT_MIN;
    int n = piles.size();
    for(int i=0; i<n; i++) {
        maxi = max(piles[i], maxi);
    }
    return maxi;
}

int minTimeRequired(vector<int> &piles, int perHour) {
    int totalHours = 0;
    int n = piles.size();
    for(int i=0; i<n; i++) {
        totalHours = totalHours + ceil((double)(piles[i])/(double)(perHour));
    }
    return totalHours;
}

int minBananasPerHour(vector<int> &piles, int h) {
    int n = piles.size();
    int low = 1;
    int high = findMax(piles);

    while(low <= high) {
        int mid = low + (high-low)/2;
        int totalHours = minTimeRequired(piles, mid);
        if(totalHours <= h) high = mid-1;
        else low = mid+1;
    }

    return low;
}

int main () {
    int n;
    cout << "N : ";
    cin >> n;

    vector<int> piles(n);
    for(int i=0; i<n; i++) {
        cin >> piles[i];
    }

    int h;
    cout << "H : ";
    cin >> h;

    int ans = minBananasPerHour(piles, h);
    cout << "The monkey should atleast eat " << ans << " bananas per hour." << endl;
}