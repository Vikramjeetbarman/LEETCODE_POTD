class Solution {
public:
    string whichsmall(string a,string b){
        if(a.length()>b.length()) return b;
        if(b.length()>a.length()) return a;

        if(a<b) return a;
        return b;
    }

    string shortestBeautifulSubstring(string s,int k){
        vector<string> ans;

        for(int i=0;i<s.length();i++){
            int p=0;

            for(int j=i;j<s.length();j++){
                if(s[j]=='1') p++;

                if(p==k){
                    ans.push_back(s.substr(i,j-i+1));
                    break;
                }
            }
        }

        if(ans.size()==0) return "";

        string mini=ans[0];

        for(int i=1;i<ans.size();i++){
            mini=whichsmall(ans[i],mini);
        }

        return mini;
    }
};