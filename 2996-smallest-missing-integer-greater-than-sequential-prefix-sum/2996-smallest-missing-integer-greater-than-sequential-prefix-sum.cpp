class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int maxsum=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]==nums[i]+1){
                sum+=nums[i+1];
            
            }
            else{
                maxsum=max(sum,maxsum);
                sum=0;
                break;
            }
        }
        maxsum = max(sum, maxsum); //finding
        while (std::find(nums.begin(), nums.end(), maxsum) != nums.end()) {
            maxsum++;
        }
        return maxsum;
    }
};