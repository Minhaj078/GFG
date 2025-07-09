class Solution {
  public:
  int parent(int x,vector<int>&par){
      if(par[x]==x) return x;
      return par[x]=parent(par[x],par);
  }
  bool dsu(int x,int y,vector<int>&par,vector<int>&sz){
      int px=parent(x,par);
      int py=parent(y,par);
      if(px==py) return false;
      
      if(sz[px]>sz[py]){
          par[py]=par[x];
          sz[px]+=sz[py];
      }else{
          par[px]=par[y];
          sz[py]+=sz[px];
      }
      return true;
  }
    int kruskalsMST(int v, vector<vector<int>> &edges) {
        // code here
        vector<int>par(v);
        for(int i=0;i<v;i++) par[i]=i;
        vector<int>sz(v,1);
        sort(edges.begin(), edges.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2]; // sort by weight
    });
        int count=0,sum=0;
        for(int i=0;i<edges.size();i++){
            if(dsu(edges[i][0],edges[i][1],par,sz)) {
                sum+=edges[i][2];
                count++;
                 if(count==v-1) break;
            }
        }
        return sum;
    }
};