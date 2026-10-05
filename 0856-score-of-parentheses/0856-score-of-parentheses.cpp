class Solution {
public:
    int scoreOfParentheses(string s) {
        int n=s.size();
        int result=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                count++;
            }
            else{
                count--;
                if(s[i-1]=='('){
                result+=pow(2,count);
                }
            }
        }
        return result;
    }
};