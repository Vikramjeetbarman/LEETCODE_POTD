class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int ans=0;
        int n=matrix.size();
        int limit=min(n,k);
        for(int i=0;i<limit;i++){
            for(int j=0;j<limit;j++){
                pq.push(matrix[i][j]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
        }

        return pq.top();
    }
};