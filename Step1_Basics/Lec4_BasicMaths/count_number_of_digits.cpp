// COUNT THE NUMBER OF DIGITS: 

    // #include<iostream>
    // using namespace std;

    // int main() {
    //     int n;
    //     cin >> n;

    //     int digits = 0;

    //     while (n > 0){
    //         digits++;
    //         n = n/10;
    //     }

    //     cout << digits << endl;

    //     return 0;
    // }

// The above approach has a time complexity of O(log10(N) + 1), and space complexity of O(1);

// OPTIMAL APPROACH TO DO THE SAME :

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = (int)(log10(n) + 1);

    cout << cnt << endl;

    return 0;
}

// The optimal approach solves the same question in O(1) time as it is just doing arithematic operations and the space complexity is also O(1);