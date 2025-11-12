class Solution {
  public:
        bool solve(int i, int j, string &txt, string &pat, vector<vector<int>> &dp) {
        // Base cases
        if (i < 0 && j < 0) return true;         // both exhausted
        if (j < 0 && i >= 0) return false;       // pattern finished but text left
        if (i < 0 && j >= 0) {                   // text finished but pattern remains
            for (int k = 0; k <= j; k++)
                if (pat[k] != '*') return false;
            return true;
        }

        // Already computed
        if (dp[i][j] != -1) return dp[i][j];

        // If current characters match or '?'
        if (txt[i] == pat[j] || pat[j] == '?')
            return dp[i][j] = solve(i - 1, j - 1, txt, pat, dp);

        // If current pattern char is '*'
        if (pat[j] == '*') {
            // Two options:
            // 1️⃣ '*' matches 0 characters → move pattern
            // 2️⃣ '*' matches 1 character → move text
            return dp[i][j] = solve(i, j - 1, txt, pat, dp) || solve(i - 1, j, txt, pat, dp);
        }

        // Otherwise no match
        return dp[i][j] = false;
    }
    bool wildCard(string &txt, string &pat) {
        int n = txt.size();
        int m = pat.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, txt, pat, dp);
    }
};