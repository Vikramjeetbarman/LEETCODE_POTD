class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
          priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
          int ans=0;
          int n=matrix.size();
          for(int i=0;i<n;i++){
             pq.push({matrix[i][0],{i,0}});

          }
          while(k--){
            auto cur=pq.top();
            pq.pop();
            int value=cur.first;
            int row=cur.second.first;
            int col=cur.second.second;
    
            if(col+1<n){
                pq.push({matrix[row][col+1],{row,col+1}});
   
                
            }
            if(k==0) return value;
          }
          return -1;
    }
};