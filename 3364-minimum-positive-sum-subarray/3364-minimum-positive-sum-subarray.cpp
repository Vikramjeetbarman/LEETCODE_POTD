class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n =nums.size();
        int mini =INT_MAX;
        while(l<=r){
            int i=0;
            while(i<=n-l){
                 int sum=0;
                 int rge=i;
                 while(rge<i+l){
                      sum+=nums[rge];
                      rge++;
                 }
                 if(sum>0){
                      mini=min(sum, mini);
                 }
                 i++;
            }
            l++;
        }
        return (mini==INT_MAX)? -1:mini; 
    }
};