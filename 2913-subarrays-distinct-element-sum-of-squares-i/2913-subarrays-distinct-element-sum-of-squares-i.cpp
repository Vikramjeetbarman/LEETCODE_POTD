class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            unordered_set<int> set;
            for(int j=i;j<n;j++){
            set.insert(nums[j]);
            res+=(set.size() * set.size());
            }
        }

        return res;
    }
};