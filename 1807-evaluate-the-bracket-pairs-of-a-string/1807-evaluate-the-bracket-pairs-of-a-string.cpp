class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        map<string , string> mp;
        for(auto ele: knowledge){
             mp[ele[0]]=ele[1];
        }
        string result="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string substr="";
                while(s[i]!=')'){
                     substr+=s[i];
                     i++;
                }
                if(mp.find(substr)!=mp.end()){
                    result+=mp[substr];
                }
                else result+='?';
                
                
            }
            else result+=s[i];
        }
        return result;
    } 
};