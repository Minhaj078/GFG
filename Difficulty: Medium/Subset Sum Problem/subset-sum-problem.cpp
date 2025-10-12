class Solution {
  public:   
  
    bool fn(int idx, int k, vector<int>& arr, vector<vector<int>>&dp){
        if(k == 0)return true;
        
        if(idx == 0)return (arr[0] == k);
        
        if(dp[idx][k] != -1)return dp[idx][k];
        
        bool notTake = fn(idx - 1, k, arr, dp);
        bool take = false;
        
        if(arr[idx] <= k){
            take = fn(idx-1, k - arr[idx], arr, dp);
        }
        
        return dp[idx][k] = (notTake | take);
    }
    
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        return fn(arr.size()-1, sum, arr, dp);
    }
};