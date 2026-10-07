class Solution {
public:
    void rec(string& s,int i,int count,int del,int& totalDel,int mask,unordered_set<int>& masks)
    {
        int n = s.length();
        if(del > totalDel || count < 0) return;
        if(i == n)
        {
            if(count == 0 && del == totalDel && masks.find(mask) == masks.end()) masks.insert(mask);
            return;
        }
        int newMask = mask | (1 << i);
        if(s[i] == '(')
        {
            rec(s,i+1,count,del+1,totalDel,mask,masks);
            rec(s,i+1,count+1,del,totalDel,newMask,masks);
        }
        else if(s[i] == ')')
        {
            rec(s,i+1,count,del+1,totalDel,mask,masks);
            rec(s,i+1,count-1,del,totalDel,newMask,masks);
        }
        else rec(s,i+1,count,del,totalDel,newMask,masks);
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length();
        int totalDel = 0,count = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(') count++;
            else if(s[i] == ')')
            {
                if(count == 0) totalDel++;
                else count--;
            }
        }
        totalDel += count;
        unordered_set<int> masks;
        rec(s,0,0,0,totalDel,0,masks);
        unordered_set<string> st;
        for(auto& mask : masks)
        {
            string t = "";
            for(int i=0;i<n;i++)
            {
                if((1 << i) & mask)
                t.push_back(s[i]);
            }
            st.insert(t);
        }
        vector<string> ans;
        for(auto& t : st) ans.push_back(t);
        return ans;
    }
};