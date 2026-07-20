class Solution {
  public:
  
    int dfs(int node, vector<vector<int>>& adj, int vis[], vector<int>&ans){
        ans.push_back(node);
        vis[node] = 1;
        
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, adj, vis, ans);
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        vector<int>ans;
        int vis[adj.size()] = {0};
        dfs(0, adj, vis, ans);
        return ans;
    }
};