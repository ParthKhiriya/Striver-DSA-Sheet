#include<iostream>
using namespace std;

int sumOfNumbers(int n) {
    if(n<=0) return 0;
    return n + sumOfNumbers(n-1);
}

int main() {
    int n;
    cin >> n;

    int sum = sumOfNumbers(n);
    cout << sum << endl;
    return 0;
}