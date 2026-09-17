class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
         vector<int> minbestlentillidx(n,INT_MAX);
         int currsum=0;
         int result=INT_MAX;
         int bestminlen=INT_MAX;
         while(j<n){
                currsum+=arr[j];
                while(i<j && currsum>target){
                    currsum -=arr[i++];
                }
                if(currsum==target){
                          int length=j-i+1;
                          if(i>0 && minbestlentillidx[i-1]!=INT_MAX){
                            result=min(result,length+minbestlentillidx[i-1]);
                          }
                          bestminlen=min(bestminlen,length);
                }
                minbestlentillidx[j]=bestminlen;
                j++;

         }
         return result==INT_MAX ? -1 :result ;
    }
};