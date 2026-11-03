class Solution {
public:
    int minMoves(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        int maxi= *max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
              result += abs(maxi-nums[i]);
        }
        return result;
    }
};