class Solution {
  public:
    int memorisation(int idx,vector<int>& height, vector<int>& dp){
        if(idx==0){
            return 0;
        }
        if(dp[idx]!=-1) return dp[idx];
        int left=memorisation(idx-1,height,dp) + abs(height[idx]-height[idx-1]);
        int right=INT_MAX;
        if(idx>1){
          right= memorisation(idx-2,height,dp) + abs(height[idx]-height[idx-2]);}
        return dp[idx]=min(left,right);
    }
    int minCost(vector<int>& height) {
        int n=height.size();
        // vector<int> dp(n+1,-1);
        //tabulation method
        // dp[0]=0;
        // for(int i=1;i<n;i++){
        //     int left=dp[i-1]+ abs(height[i]-height[i-1]);
        //     int right=INT_MAX;
        //     if(i>1){
        //         right=dp[i-2]+ abs(height[i]-height[i-2]);
        //     }
        //     dp[i]=min(left,right);
        // }
        // return dp[n-1];
        //space optimisation
        int prev2=0;
        int prev=0;
        for(int i=1;i<n;i++){
            int left=prev + abs(height[i]-height[i-1]);
            int right=INT_MAX;
            if(i>1){
                right=prev2 + abs(height[i]-height[i-2]);
            }
            int curr=min(left,right);
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    } 
};