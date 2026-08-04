class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int a=nums[0];
        int b=nums[nums.size()-1];
        set<int> se;
        for(int i=0;i<nums.size();i++){
               se.insert(nums[i]);
        }
        while(a!=b){
            if(se.find(a)!=se.end()){
                a++;
            }
            else {
                ans.push_back(a);
                a++;
            }
        }
        return ans;
    }
};