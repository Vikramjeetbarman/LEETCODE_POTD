class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> parpos{};
        string ans{};
        int j = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(')
                parpos.push_back(ans.length());
            else if(s[i] == ')')
            {
                j = parpos.back();
                parpos.pop_back();
                reverse(ans.begin()+j, ans.end());
            }
            else
                ans += s[i];
        }
        return ans;
    }
};