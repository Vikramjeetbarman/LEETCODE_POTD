class Solution {
public:
    bool isPalindrome(string s) {
        int i=0;
        int j=(s.size()-1);
        while(i<=j){
            char ch1=s[i];
            char ch2=s[j];
            
            if(65<=ch1 && ch1<=90 || 97<=ch1 && ch1<=122|| 48<=ch1 && ch1<=57){
                 if(65<=ch1 && ch1 <=90) ch1+=32;
            }
            else {i++; continue;}
            if(65<=ch2 && ch2<=90 || 97<=ch2 && ch2<=122 || 48<=ch2 && ch2<=57){
                  if(65<=ch2 && ch2<=90) ch2+=32;
            }
            else {j--; continue;}
            if(ch1==ch2){
                i++;
                j--;
            }
            else return false;

        }
        return true;


    }
};