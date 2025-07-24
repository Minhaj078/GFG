
class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int maxi = 0, cnt = 0;
        
        for(int i = 1; i < arr.size(); ++i) {
            if(arr[i] > arr[i - 1]) {
                cnt++;
            }
            else cnt = 0;
            maxi = max(maxi, cnt);
        }
        
        return maxi;
    }
};