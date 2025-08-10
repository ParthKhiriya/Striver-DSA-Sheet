#include<bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    int adjmat[n+1][n+1] = {0};
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adjmat[u][v] = 1;
        adjmat[v][u] = 1;
    }

    return 0;
}