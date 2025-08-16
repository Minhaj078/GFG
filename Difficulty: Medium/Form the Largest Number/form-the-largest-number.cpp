class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string findLargest(vector<int> &arr) {
        vector<string> arrr;
        for (int x : arr) arrr.push_back(to_string(x));

        sort(arrr.begin(), arrr.end(), cmp);

        if (arrr[0] == "0") return "0";

        string ans = "";
        for (string s : arrr) ans += s;
        return ans;
    }
};
