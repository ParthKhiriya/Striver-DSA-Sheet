// The below is the Brute Force approach for solving this question.

    // #include<iostream>
    // using namespace std;

    // int main() {
    //     int n;
    //     cin >> n;

    //     for(int i = 1; i<=n; i++){
    //         if(n%i==0) cout << i << " ";
    //     }
    //     return 0;
    // }

// Now using the optimal way, we can solve the question like this -- 

    // #include<iostream>
    // #include<vector>
    // #include<algorithm>
    // using namespace std;

    // int main() {
    //     int n;
    //     cin >> n;

    //     vector<int> ans;

    //     for(int i = 1; i*i<=n; i++){
    //         if(n%i==0) {
    //             ans.push_back(i);
    //             if((n/i) != i) {
    //                 ans.push_back(n/i);
    //             }
    //         }
    //     }

    //     sort(ans.begin(), ans.end());
    //     for(auto it: ans) cout << it << " ";
    //     return 0;
    // }

// Here, the factors are found in O(sqrt(n)), in the above approach it took O(n).