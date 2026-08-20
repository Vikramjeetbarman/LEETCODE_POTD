class Solution {
public:
    bool check(vector<int>& arr) {
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            if(i==n-1){
                if(arr[n-1]>arr[0]) count++;
            }
            else if(arr[i]>arr[i+1]){
            count++;
            }
            // simply we can also use arr[i]>arr[(i+1)%n] instead of manually checking the last element with first as for circular
            
            if(count>1 ) return false;
        }
        return true;
    }
};