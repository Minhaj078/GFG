#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSuperSeq(string &s1, string &s2) {  // 👈 renamed to match driver
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }

        int i = n, j = m;
        string result;
        while (i > 0 && j > 0) {
            if (s1[i-1] == s2[j-1]) {
                result.push_back(s1[i-1]);
                --i; --j;
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                result.push_back(s1[i-1]);
                --i;
            } else {
                result.push_back(s2[j-1]);
                --j;
            }
        }
        while (i > 0) result.push_back(s1[i-1]), --i;
        while (j > 0) result.push_back(s2[j-1]), --j;

        reverse(result.begin(), result.end());
        int ans = result.size();
        return ans;
    }
};
