class Solution {
public:
    int minAddToMakeValid(string s) {
       int n=s.size();
       int count=0;
       int rem=0;
       for(int i=0;i<n;i++){
        if(s[i]=='(') count++; //for opened
        else if(count!=0) count--; //for each opened that is closing
            
        else rem++;// for extra opens hence will add it to the final answer
       }
       return count+rem;
    }
};
