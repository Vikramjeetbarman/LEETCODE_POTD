class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD=1e9+7;
        vector<int> dp(n,1);
        vector<int> countendwith(26,0);
        int sum=0;
        for(int i=0; i<n;i++){
            int idx=s[i]-'a';
            dp[i]=(1 + sum - countendwith[idx]+MOD)%MOD;
            sum=(sum+dp[i])%MOD;
            countendwith[idx]=(countendwith[idx] + dp[i])%MOD;
        }
        return sum;
    }
};