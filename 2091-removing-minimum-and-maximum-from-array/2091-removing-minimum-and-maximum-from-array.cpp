class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int minPos=0;
        int maxPos=0;
        
        for (int i=0; i<n; i++) {
            if (nums[i]<nums[minPos]) minPos = i;
            if (nums[i]>nums[maxPos]) maxPos = i;
        }
        int left = min(minPos, maxPos);
        int right = max(minPos, maxPos);
        
        int fromFront = right + 1;
        int fromBack = n - left;
        int fromBothEnds = (left + 1) + (n - right);
        
        return min(fromFront, min(fromBack, fromBothEnds));
    }
};