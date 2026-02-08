// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int lowest = arr[0], highest = arr[0], prevHighest = highest, ans = arr[0];
        for (int i=1;i<arr.size();i++) {
            highest = max({arr[i], highest*arr[i], lowest*arr[i]});
            lowest = min({arr[i], lowest*arr[i], prevHighest*arr[i]});
            prevHighest = highest;
            ans = max({ans, highest});
        }
        return ans;
    }
};