class Solution {
public:
    vector<string> ans;

    bool valid(string part) {
        if (part.size() > 1 && part[0] == '0') return false;
        int num = stoi(part);
        return num <= 255;
    }

    void backtrack(string &s, int idx, int parts, string curr) {
        if (parts == 4) {
            if (idx == s.size()) {
                curr.pop_back();
                ans.push_back(curr);
            }
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);

            if (!valid(part)) continue;

            backtrack(s, idx + len, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        ans.clear();

        if (s.size() < 4 || s.size() > 12) return ans;

        backtrack(s, 0, 0, "");

        return ans;
    }
};