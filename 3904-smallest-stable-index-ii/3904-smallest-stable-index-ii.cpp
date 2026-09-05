class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefmax(n);
        vector<int> suffmin(n);
        prefmax[0]=nums[0];
        int max=prefmax[0];
        suffmin[n-1]=nums[n-1];
        int min=nums[n-1];
        for(int i=1;i<n;i++){
            if(nums[i]>=max){
                 max=nums[i];
                 prefmax[i]=nums[i];
            }
            else prefmax[i]=max;
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i]<=min){
                 min=nums[i];
                 suffmin[i]=nums[i];
            }
            else suffmin[i]=min;
        }
        for(int i=0;i<n;i++){
            if((prefmax[i]-suffmin[i])<=k) return i;
        }
        return -1;
       
    }
};