class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.length();
        unordered_map<char,int> mp;
        int j=0;
        int maxlen=0;
        int i=0;
        while(i<n){
            mp[s[i]]++;
            while(j<n && mp[s[i]]>2 ){
                 mp[s[j]]--;    
                 j++;
            }
            i++;
            maxlen=max(maxlen,i-j)   ;
        }
        return maxlen;
    }
};