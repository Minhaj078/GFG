class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        unordered_map<char,int>mp;
        int maxi = -1, left = 0;
        for(int i = 0;i < s.size();i++){
            mp[s[i]]++;
            while(mp.size() > k){
                mp[s[left]]--;
                if(mp[s[left]] == 0)mp.erase(s[left]);
                left++;
            }
            if(mp.size() == k)maxi = max(maxi, i - left + 1);
        }
        return maxi;
    }
};