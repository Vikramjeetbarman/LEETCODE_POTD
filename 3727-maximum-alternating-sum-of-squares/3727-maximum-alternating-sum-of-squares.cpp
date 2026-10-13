class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
         int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0) nums[i]*=(-1);
        }
        sort(nums.begin(),nums.end());
        long long pos2=0;
        long long neg2=0;
        for(int i=0;i<n;i++){
              if(i<n/2) neg2+=(nums[i]*nums[i]);
              else pos2+=(nums[i]*nums[i]);
        }
        return pos2-neg2;

    }
};