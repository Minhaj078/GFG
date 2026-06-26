class Solution {
public:
    bool detect(int src, vector<int> adj[], int vis[]) {
        vis[src] = 1;

        queue<pair<int, int>> q;
        q.push({src, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjNode : adj[node]) {

                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push({adjNode, node});
                }
                else if (parent != adjNode) {
                    return true;
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<int> adj[V];

        // Create adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int vis[V] = {0};

        // Check every component
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis))
                    return true;
            }
        }

        return false;
    }
};