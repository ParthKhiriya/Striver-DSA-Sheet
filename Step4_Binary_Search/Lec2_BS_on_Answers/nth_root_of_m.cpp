#include<bits/stdc++.h>
using namespace std;

int funcn(int mid, int n, int m) {
    long long ans = 1;
    for(int i=1; i<=n; i++) {
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}

int nthRoot(int n, int m) {
    int low = 0;
    int high = m;

    while(low <= high) {
        int mid = low + (high-low)/2;
        int midN = funcn(mid, n, m); 

        if(midN == 1) return mid;
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }
    return -1;
}

int main () {
    int n;
    cout << "N : ";
    cin >> n;

    int m;
    cout << "M : ";
    cin >> m;

    cout << "The Nth root of M is : " << nthRoot(n, m);

    return 0;
}