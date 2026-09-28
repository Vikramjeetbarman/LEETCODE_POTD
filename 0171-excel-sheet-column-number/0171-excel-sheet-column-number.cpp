class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        long long ans=0;
        long long multiple=1;
        for(int i=n-1;i>=0;i--){
             int x=columnTitle[i]-'A';
             ans += multiple*(x+1);
             multiple *=26;

        }
        return ans;
    }
};