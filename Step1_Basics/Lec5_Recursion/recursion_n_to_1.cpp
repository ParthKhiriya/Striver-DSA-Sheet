#include<iostream>
using namespace std;

void printNumbers(int n) {
    if(n<=0) return;
    cout << n << " ";
    printNumbers(n-1);
}

int main() {
    int n;
    cin >> n;

    printNumbers(n);
    return 0;
}

// TC: O(N)
// SC: O(N)