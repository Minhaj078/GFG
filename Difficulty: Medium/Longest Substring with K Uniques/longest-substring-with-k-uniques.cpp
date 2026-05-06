class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mp;
        int left = 0,maxLen = -1;
        for(int r = 0;r<s.size();r++){
            mp[s[r]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0)mp.erase(s[left]);
                left++;
            }
            if(mp.size() == k)maxLen = max(maxLen, r - left + 1);
        }return maxLen;
    }
};