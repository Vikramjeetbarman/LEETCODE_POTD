class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0;
        int j=0;
        int currsum=0;
        int result=INT_MAX;
        int bestminidx=INT_MAX;
        vector<int> bestminidxtill(n,INT_MAX);
        while(j<n){
            currsum+=arr[j];
            while(i<j && currsum> target){
                currsum -= arr[i++];

            }
            if(currsum==target){
                int len=j-i+1;
                if(i>0 && bestminidxtill[i-1]!=INT_MAX){
                  result=min(result,len+bestminidxtill[i-1]);
                }
                  bestminidx=min(bestminidx,len);
                
            }
            bestminidxtill[j]=bestminidx;
            j++;
        }
        return result== INT_MAX ? -1 : result;
    }
};