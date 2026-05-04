class Solution {
  public:
    int countTriplets(int sum, vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int cnt = 0;
        for(int i = 0;i<n-2;i++){
            int l = i+1, r = n-1;
            while(l < r ){
                long long t = arr[i] + arr[l] + arr[r];
                if(t < sum){
                    cnt += (r - l);
                    l++;
                }
                else{
                    r--;
                }
            }
        }
        return cnt;
    }
};