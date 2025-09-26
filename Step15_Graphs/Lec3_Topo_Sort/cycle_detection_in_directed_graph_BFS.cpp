class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<int> indegree(V, 0);
        queue<int> q;
        vector<vector<int>> adjList(V);
        int count = 0;
        
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }
        
        for(int i=0; i<V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            
            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) q.push(adjNode);
            }
        }
        
        if(count == V) {
            return false;
        }
        
        return true;
    }
};