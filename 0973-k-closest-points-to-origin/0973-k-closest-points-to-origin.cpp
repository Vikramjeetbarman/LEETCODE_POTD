class Solution {
public:
   typedef pair<int,vector<int>> p;
   typedef long long ll;
    ll distance(int a, int b){
        ll ans=pow(a,2)+pow(b,2);
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
       priority_queue<p> pq;
       for(auto ele : arr){
            pq.push({distance(ele[0],ele[1]),ele});
            if(pq.size()>k) pq.pop();
       }
       vector<vector<int>> ans;
       while(pq.size()!=0){
           ans.push_back(pq.top().second);
           pq.pop();
       }
       return ans;
    }
};