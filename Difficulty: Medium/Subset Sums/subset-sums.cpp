class Solution {
  public:
  
    void subSum(int indx,int sum,vector<int>&ans,vector<int>arr){
        if(indx == arr.size()){
            ans.push_back(sum);
            return;
        }
        
        subSum(indx+1,sum+arr[indx],ans,arr);
        subSum(indx+1,sum,ans,arr);
    }
    
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        vector<int>ans;
        int sum = 0;
        subSum(0,sum,ans,arr);
        return ans;
    }
};