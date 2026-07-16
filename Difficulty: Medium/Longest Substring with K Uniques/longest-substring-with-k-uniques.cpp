class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int left = 0, right = 0, maxLen = INT_MIN;
        unordered_map<char,int>mp;
        
        while(right < s.size()){
            mp[s[right]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0)mp.erase(s[left]);
                left++;
            }
            if(mp.size() == k) maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen == INT_MIN ? -1:maxLen;
    }
};