class Solution {
public:
    typedef pair<int,int> p;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<p,vector<p>, greater<p>> pq;
        vector<int> ans;
        for(auto ele: mp){
            int val=ele.first;
            int frq=ele.second;
             pq.push({frq,val});
             if(pq.size()>k){
                pq.pop();
             }    
        }
        while(pq.size()!=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};