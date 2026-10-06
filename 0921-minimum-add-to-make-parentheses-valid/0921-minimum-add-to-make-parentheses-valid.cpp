class Solution {
public:
    int minAddToMakeValid(string s) {
       int n=s.size();
       int count=0;
       int rem=0;
       for(int i=0;i<n;i++){
        if(s[i]=='(') count++;
        else if(count!=0) count--;
        else rem++;
       }
       return count+rem;
    }
};