class Solution {
public:
    int check(int y){
        int sum=0;
        while(y>0){
            int d=y%10;
            sum+=d;
            y/=10;
  }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        int ans= -1;
        for(int i=0;i<n;i++){
            int x=check(nums[i]);
            if(x==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};