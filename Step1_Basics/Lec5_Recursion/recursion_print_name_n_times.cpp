#include<iostream>
using namespace std;

void printName(int i, int n){
    if(i>n) return;
    cout << "Parth" << endl;
    printName(i+1, n);

}

int main() {
    int n;
    cin >> n;

    printName(1, n);
    return 0;
}

// The TC of the above code will be O(N) because we are calling recursion function n times and each time it is performing the task which takes O(1) time, so total O(N);
// Similarly, the space complexity will also be O(N), because the stack space can reach a maximum of N elements while performing the task.