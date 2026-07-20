class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        int vis[n] = {0};
        
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        vector<int>ans;
        
        while(!q.empty()){
            int sz = q.size();
            int node = q.front();
            q.pop();
            
            
            ans.push_back(node);
            
            for(auto it : adj[node]){
                
                if(!vis[it])
                    q.push(it);
                    vis[it] = 1;
                }
            }
        return ans;
    }
};