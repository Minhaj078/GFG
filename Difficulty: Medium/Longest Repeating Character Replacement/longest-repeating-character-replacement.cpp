class Solution {
  public:
    int longestSubstr(string& s, int k) {
        // code here
        int l = 0, maxFreq = 0, maxLen = 0;
        unordered_map<char,int>mp;
        
        for(int r = 0;r<s.size();r++){
            mp[s[r]]++;
            maxFreq = max(maxFreq, mp[s[r]]);
            
            while((r - l + 1) - maxFreq > k){
                mp[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r - l + 1);
        }return maxLen;
        
    }
};