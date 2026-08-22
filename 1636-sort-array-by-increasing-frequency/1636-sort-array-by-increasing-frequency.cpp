class Solution {
public:
typedef pair<int,int> p;
 static bool mycomp(p a, p b){
        if(a.first==b.first){
            if(a.second>b.second) return true;
            else return false;
        }
        if(a.first<b.first) return true;
        else  return false;
        }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int ,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
             mp[nums[i]]++;
        }
        vector<p> ans;
        for(auto ele: mp){
            int val=ele.first;
            int freq=ele.second;
            ans.push_back({freq,val});
        }
        
        vector<int> finalans;
        sort(begin(ans),end(ans),mycomp);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].first;j++){
                finalans.push_back(ans[i].second);
            }
        }
        return finalans;

    }
};