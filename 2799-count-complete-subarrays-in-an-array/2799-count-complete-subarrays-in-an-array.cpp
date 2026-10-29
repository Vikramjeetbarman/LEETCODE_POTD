class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        set<int> a;
        for(int i=0;i<n;i++){
            a.insert(nums[i]);
        }
        int s=a.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            set<int> l;
            for(int j=i;j<n;j++){
                   l.insert(nums[j]);
                   if(l.size()==s) ans++;
            }
        }
        return ans;

    }
};