class Solution {
  public:
  
bool checkCycle(int node, int parent, vector<int> adj[], int vis[]) {
    vis[node] = 1;

    for (auto it : adj[node]) {
        if (!vis[it]) {
            if (checkCycle(it, node, adj, vis))
                return true;
        }
        else if (it != parent) {
            return true;
        }
    }

    return false;
}
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int> adj[V];

        // Create adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int vis[V] = {0};
        
        for(int i = 0;i<V;i++){
            if(!vis[i]){
                if(checkCycle(i, -1, adj, vis))return true;
            }
        }
        return false;
    }
};