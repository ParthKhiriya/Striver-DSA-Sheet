class Solution {
  private: 
    void dfs(int node, int V, vector<vector<int>>& adjList, vector<int>& vis, vector<int>& ans, stack<int>& st) {
        vis[node] = 1;
        for(auto adjNode: adjList[node]) {
            if(vis[adjNode] == 0) {
                dfs(adjNode, V, adjList, vis, ans, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int> vis(V, 0);
        vector<int> ans;
        // stack<int> st; // used only in DFS.
        vector<int> indegree(V, 0);
        queue<int> q;
        
        vector<vector<int>> adjList(V);
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
            ans.push_back(node);
            
            for(auto adjNode: adjList[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        
        // THIS IS THE PART OF THE DFS APPROACH TO SOLVE THIS QUESTION: 
        
        // for(int i=0; i<V; i++) {
        //     if(vis[i] == 0) {
        //         dfs(i, V, adjList, vis, ans, st);
        //     }
        // }
        
        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        
        return ans;
    }
};