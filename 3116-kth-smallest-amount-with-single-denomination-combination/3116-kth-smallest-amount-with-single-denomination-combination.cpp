class Solution {
public:
    typedef long long ll;
    ll countelementleft(int mid,vector<int>& coins){
           ll n=coins.size();
           ll countnum=0;
           for(int expression=1;expression<=(1<<n)-1;expression++){
            ll lcm=0;
                 int order=0;
                 for(int i=0;i<n;i++){
                        if(expression & 1<<i) {
                            order++;

                        if(lcm==0){
                            lcm=coins[i];
                        }
                        else{
                            lcm=lcm*coins[i]/gcd(lcm,coins[i]);
                        }
                 }
           }
                 if(order%2==0){ 
                    countnum -= mid/lcm;
                 }
                 else countnum +=mid/lcm;

           }
           return countnum;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        ll result=-1;
        ll l=1;
        ll r= (ll)(*max_element(coins.begin(),coins.end())*k);
        ll mid=0;
        while(l<=r){
            mid=l+(r-l)/2;
            if(countelementleft(mid,coins)>=k){
                result=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return result;
    }
};