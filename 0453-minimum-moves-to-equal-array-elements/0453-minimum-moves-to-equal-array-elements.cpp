class Solution {
public:
    int minMoves(vector<int>& nums){
        int n=nums.size();
        int mini= *std::min_element(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int result=sum-(n*mini);
        return result;
    }
};