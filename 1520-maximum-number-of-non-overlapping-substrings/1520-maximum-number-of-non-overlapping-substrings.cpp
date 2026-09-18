class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n);
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            first[x] = min(first[x], i);
            last[x] = i;
        }
        vector<vector<int>> p;
        for (int i = 0; i < n; i++) {
            int x = s[i] - 'a';
            if (i != first[x])
                continue;
            int j = last[x];
            bool valid = true;
            for (int k = i; k <= j; k++) {
                int c = s[k] - 'a';
                if (first[c] < i) {
                    valid = false;
                    break;
                }
                j = max(j, last[c]);
            }
            if (valid) {
                p.push_back({i, j});
            }
        }
        sort(p.begin(), p.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        vector<vector<int>> ans;
        int lastEnd = -1;
        for (auto &range : p) {
            if (range[0] > lastEnd) {
                ans.push_back(range);
                lastEnd = range[1];
            }
        }
        vector<string> finalans;
        for (auto &range : ans) {
            finalans.push_back(
                s.substr(range[0], range[1] - range[0] + 1)
            );
        }
        return finalans;
    }
};