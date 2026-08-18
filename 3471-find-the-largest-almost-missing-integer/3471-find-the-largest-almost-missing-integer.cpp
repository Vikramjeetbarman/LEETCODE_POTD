class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {

        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        map<int,int>freq;
        for (int x:nums) {
            freq[x]++;
        }
        if(k==1){
            int ans=-1;
            for(auto& [val,count]:freq){
                if(count==1){
                    ans=max(ans,val);
                }
            }
            return ans;
        }
        if(n==k){
            return *std::max_element(nums.begin(),nums.end());
        }
        if(nums[0]==nums[n-1]  && n==k) return nums[0];
        if(nums[0]==nums[n-1]) return -1;
        
        
        int count1=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==nums[0]) count1++;
            if(nums[i]==nums[n-1]) count2++;

        }
        if(count1>=2 && count2>=2){
            return -1;
        }
        else if(count1<2 && count2<2){
            return max(nums[0],nums[n-1]);
        }
        else{
            if(count1<2) return nums[0];
            else return nums[n-1];
        }
    }
};