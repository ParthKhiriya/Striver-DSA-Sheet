// User function Template for C++
class Solution {
  private:
    void topoSort(int node, vector<vector<pair<int, int>>>& adjList, vector<int>& vis, stack<int>& st) {
        vis[node] = 1;
        for(auto adjNode: adjList[node]) {
            int v = adjNode.first;
            if(!vis[v]) {
                topoSort(v, adjList, vis, st);
            }
        }
        
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adjList(V);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            int edgeWeight = it[2];
            adjList[u].push_back({v, edgeWeight});
        }
        
        vector<int> vis(V, 0);
        stack<int> st;
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topoSort(i, adjList, vis, st);
            }
        }
        
        vector<int> dist(V, INT_MAX);
        dist[0] = 0; // source is alwasy 0 here
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            
            if(dist[node] != INT_MAX) { // process only if reachable
                int distance = dist[node];
                for(auto adjNode: adjList[node]) {
                    int v = adjNode.first;
                    int wt = adjNode.second;
                    if(distance + wt < dist[v]) {
                        dist[v] = distance + wt;
                    }
                }
            }
        }
        
        for(int i=0; i<V; i++) {
            if(dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }
        
        return dist;
        
    }
};
