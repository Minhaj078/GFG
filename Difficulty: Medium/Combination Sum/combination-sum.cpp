// User function template for C++

class Solution {
  public:
  
  
    void csum(int indx,vector<int>arr,int target,vector<vector<int>>&ans,vector<int>&ds){
        
        if(indx == arr.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
        
        //pick the element
        
        if(arr[indx] <= target){
            ds.push_back(arr[indx]);
            csum(indx,arr,target-arr[indx],ans,ds);
            ds.pop_back();
        }
        
        //not pick 
        csum(indx+1,arr,target,ans,ds);
    }
  
    // Function to find all combinations of elements
    // in array arr that sum to target.
    vector<vector<int>> combinationSum(vector<int> &arr, int target) {
        // Your code here
        
        vector<int>ds;
        vector<vector<int>>ans;
        
        csum(0,arr,target,ans,ds);
        return ans;
    }
};