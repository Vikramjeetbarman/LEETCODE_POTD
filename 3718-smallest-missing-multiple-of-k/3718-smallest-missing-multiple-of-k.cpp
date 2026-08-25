class Solution {
public:
   typedef long long ll;
    int missingMultiple(vector<int>& nums, int k) {
        priority_queue<ll,vector<ll>,greater<ll>> pq;
        int count=0;
        for(auto ele : nums){
            if(ele%k==0){
               pq.push(ele);
               count++;
            }
            else continue;
        }
        if(count==0) return k;
        
        if((pq.top()%k)>=2) return k;
        ll quotient=1;
        while(pq.size()!=0){
             if(pq.top()==quotient*k){
                 pq.pop();
                 quotient++;
             }
             else if(pq.top()<quotient*k) pq.pop();
             else return quotient*k;
        }
        return quotient*k;
    }
};