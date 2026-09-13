class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<vector<int>> pos1;
        vector<vector<int>> pos2;
        
        int n=img1[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    pos1.push_back({i,j});
                }
                if(img2[i][j]==1){
                     pos2.push_back({i,j});
                }
            }
        }
        int finalans=0;
        map<pair<int,int>, int> mp;
        for(auto p1:pos1){
            for(auto p2 :pos2){
                 int r= p2[0] -  p1[0];
                 int c= p2[1] - p1[1];
                 mp[{r,c}]++;
                 finalans=max(finalans,mp[{r,c}]);
            }
        }
        
        return finalans;

    }
};