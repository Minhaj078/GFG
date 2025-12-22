class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        
        sort(arr,arr + n);
        long long cnt = 0;
        
        for(int i = 0; i<n-2; i++){
            int left = i + 1, right = n - 1;
            
            while(left < right){
                long long target = arr[i] + arr[left] + arr[right];
                
                if(target < sum){
                    cnt += (right - left);
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return cnt;
    }
};