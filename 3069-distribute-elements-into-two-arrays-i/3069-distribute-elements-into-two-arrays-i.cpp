class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n=nums.size();
         vector<int> arr1(n,0);
         vector<int> arr2(n,0);
         vector<int> res;
         arr1[0]=nums[0];
         arr2[0]=nums[1];
         int k=0;
         int j=0;
         for(int i=2;i<nums.size();i++){
            if(arr1[k]>arr2[j]){
                k++;
                arr1[k]=nums[i];
            }
            else{
                j++;
                arr2[j]=nums[i];
            }
         }
         for(int s=0;s<arr1.size();s++){
              if(arr1[s]==0) continue;
              res.push_back(arr1[s]);
         }
         for(int s=0;s<arr2.size();s++){
              if(arr2[s]==0) continue;
              res.push_back(arr2[s]);
         }
         return res;


    }
};