class Solution {
public:
   typedef pair<int , int > p;

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<p> pq;
        for(int ele : arr){
            pq.push({abs(x-ele),ele});
            if(pq.size()>k){
                 pq.pop();
            }
        }
        vector<int> ans;
        while(pq.size()!=0){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(begin(ans),end(ans));
        return ans;
    }
};