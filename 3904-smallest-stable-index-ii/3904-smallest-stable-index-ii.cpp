class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suf(n);
        vector<int>pref(n);
        pref[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pref[i]=max(nums[i],pref[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suf[i]=min(suf[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            int temp=pref[i]-suf[i];
            if(temp<=k)return i;
        }
        return -1;
    }
};