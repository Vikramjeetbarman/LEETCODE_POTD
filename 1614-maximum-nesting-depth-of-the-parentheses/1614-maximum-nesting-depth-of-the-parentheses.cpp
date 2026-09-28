class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int nestedparenthesis=0;
        int maxi=0; //iterate
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                nestedparenthesis++;
                maxi=max(maxi,nestedparenthesis);
            }
            else if(s[i]==')'){
                nestedparenthesis--;
            }
            else continue;
        }
        return maxi;
    }
};
