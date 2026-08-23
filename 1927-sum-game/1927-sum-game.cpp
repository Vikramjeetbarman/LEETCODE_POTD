class Solution {
public:
  typedef long long ll;
    bool sumGame(string nums) {
        ll countl=0;
        ll countr=0;
        ll suml=0;
        ll sumr=0;
        for(ll i=0;i<nums.size()/2;i++){
            if(nums[i]=='?') countl++;
            else suml+=(nums[i]-'0');
        }
        for(ll j=nums.size()/2;j<nums.size();j++){
             if(nums[j]=='?') countr++;
             else sumr+=(nums[j]-'0');
        }
        if((countl+countr)%2!=0) return true;
        if((suml-sumr)==(countr-countl)/2 * 9) return false;
        return true;


    }
};