class Solution {
  public:
    int longestUniqueSubstring(string &s) {
        // code
        int left = 0, right = 0, maxi = INT_MIN;
        
        unordered_map<char,int>mp;
        
        while(right < s.size()){
            mp[s[right]]++;
            
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                if(mp[s[left]] == 0)mp.erase(mp[s[left]]);
                left++;
            }
            maxi = max(maxi, right - left + 1);
            right++;
        }return maxi;
    }
};