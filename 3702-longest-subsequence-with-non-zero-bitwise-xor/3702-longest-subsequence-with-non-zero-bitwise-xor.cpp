class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        bool zero= all_of(nums.begin(),nums.end(),[](int x){return x==0;});
        if (zero)return 0;
        return total!=0? nums.size():nums.size()-1;
    }
};