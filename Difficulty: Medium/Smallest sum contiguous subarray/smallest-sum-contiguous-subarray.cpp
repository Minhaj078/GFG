// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int sum = 0, mini = INT_MAX;
        
        for(auto it :a){
            sum += it;
            mini = min(mini,sum);
            
            if(sum > 0)sum = 0;
        }return mini;
    
    }
};
