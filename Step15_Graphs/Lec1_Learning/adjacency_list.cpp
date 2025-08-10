#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<int> adjList[n+1];
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[u].push_back(u); // For directed graph, we do not need to do this step
    }
    
    return 0;
}