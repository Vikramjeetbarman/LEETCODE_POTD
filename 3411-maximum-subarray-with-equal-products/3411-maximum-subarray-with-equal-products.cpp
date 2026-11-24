class Solution {
public:
    int maxLength(vector<int>& nums) {
        int b=2,l=0,p=1;
        for (int r=0; r<ssize(nums);++r){
            int x=nums[r];
            while(gcd(p,x) > 1)
                p/=nums[l++];
            p*=x;
            b=max(b,r-l+1);
        }
        return b;
    }
};