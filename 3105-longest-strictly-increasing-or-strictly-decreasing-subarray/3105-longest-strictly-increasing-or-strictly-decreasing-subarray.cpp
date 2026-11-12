class Solution {
public:
    int longestMonotonicSubarray(vector<int>& s) {
        int n=s.size();
        long long si=1;
        long long maxisi=1;
        long long sd=1;
        long long maxisd=1;
        for(int i=0;i<n-1;i++){
             
            if(s[i+1]>s[i]){
                si++;
                maxisi= max(si,maxisi);
            }
            else si=1;
            if(s[i+1]<s[i]){
                sd++;
                maxisd= max(sd,maxisd);
            }
            else sd=1;
        }
        long long finalans= max(maxisi,maxisd);
        return finalans;
    }
};