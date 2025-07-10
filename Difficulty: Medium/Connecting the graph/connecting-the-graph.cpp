// User function Template for C++

class DisjointSet {
    public:
    vector<int> parent, size;
    
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int  i =0;i< n;i++){
            parent[i] = i;
        }
    }
        
        int findPar(int node){
            if(node == parent[node])return node;
            
            return parent[node] = findPar(parent[node]); 
            //recursively find the parent it will work after when union will be there
            /*
            Before union:
            parent = [0,1,2,3,4,5,6]

            After:
            union(2,4)
            union(4,6)

            parent = [0,1,2,3,2,5,4]  // 6→4→2
            
            findPar(6)
            → findPar(4) → findPar(2) ⇒ 2
            
            Path compression:
            → parent[6] = 2
            → parent[4] = 2

            */
        }
        
            void unionBySize(int u, int v) {
            int pu = findPar(u);
            int pv = findPar(v);
            if (pu == pv) return;
            if (size[pu] < size[pv]) {
                parent[pu] = pv;
                size[pv] += size[pu];
            } else {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
    }
};

class Solution {
public:
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cntExtras = 0;

        for (auto it : edge) {
            int u = it[0];
            int v = it[1];

            if (ds.findPar(u) == ds.findPar(v)) {
                // edge is redundant
                cntExtras++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        // Count number of disconnected components
        int cntC = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i)
                cntC++;
        }

        int ans = cntC - 1; // number of operations needed

        if (cntExtras >= ans)
            return ans;
        return -1;
    }
};