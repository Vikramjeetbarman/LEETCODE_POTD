class Solution {
public:
    int findMin(vector<int>& nums) {
        priority_queue<int,vector<int> , greater<int>> pq;
        for(auto ele:nums){
            pq.push(ele);
            if(pq.top()>ele) break;
        }
        return pq.top();
    }
};