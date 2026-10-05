class Solution {
public:
    int scoreOfParentheses(string s){
        int n=s.size();
        int result=0;
        int count2=0;
        stack<char> st;
        for(int i=0 ; i<n ; i++){
            if(s[i]=='('){
                count2++;
            }
            else{
                count2--;
                if(s[i-1]=='('){
                   result+=pow(2,count2);
                }
            }
            
        }
        return result;

    }
};