class Solution {
public:
    bool divideArray(vector<int>& nums) {
    unordered_map<int ,int> n;
    for(auto ele:nums){
        n[ele]++;
    }
    for(auto ele:n){
        int b=ele.second;
        if(b%2!=0) return false;
    }
    return true;

    }
};