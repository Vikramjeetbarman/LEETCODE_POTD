class Solution {
public:
    int findMin(vector<int>& ans) {
          int l=0;
          int r=ans.size()-1;
          int mid=0;
          while(l<r){
               mid=l+(r-l)/2;
               if(ans[mid]<ans[r]){
                     r=mid;
               }
               else if(ans[mid]>ans[r]){
                    l=mid+1;
               }
               else if(ans[mid]==ans[r]){
                r--;
               }
                
          }
          return ans[l];
    }
};