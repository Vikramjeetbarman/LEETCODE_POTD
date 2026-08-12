class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        int i=0;
        int j=0;
        int result =0;
        while(j<n){
              mp[nums[j]]++;
              while(j<n && mp[nums[j]]>k){
                mp[nums[i]]--;
                i++;
              }
              result=max(result,j-i+1);
              j++;

        }
        return result;



    }
};