class Solution {
  public:
  
    void fn(int i, vector<int>&ds,vector<vector<int>>&ans,vector<int>&arr){
        
        if(i == arr.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(arr[i]);
        fn(i+1, ds, ans, arr);
        ds.pop_back();
        fn(i+1, ds, ans, arr);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<int>ds;
        vector<vector<int>>ans;
        
        fn(0,ds,ans,arr);
        return ans;
    }
};