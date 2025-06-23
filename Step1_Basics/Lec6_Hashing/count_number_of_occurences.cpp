#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main() {

    int arr[10];
    for(int i=0;i<10;i++) {
        cin >> arr[i];
    }

    map<int, int> mp;
    for(int i=0;i<10;i++) {
        mp[arr[i]]++;
    }

    for(auto it: mp) {
        cout << it.first << " occurs " << it.second << " times " << endl;
    }

    return 0;
}