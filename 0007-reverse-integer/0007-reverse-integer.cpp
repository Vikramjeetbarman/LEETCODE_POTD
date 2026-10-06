class Solution {
public:
    typedef long long ll;
    int reverse(int x) {
        bool flag=true;
        ll n=x;
        if(x<0){
            n*=(-1);
            flag=false;
        }
         ll res=0;
        ll mul=0;
        ll k=n;
        while(k>0){
            k/=10;
            mul++;
        }
        mul--;
        while(n>0){
            ll d=n%10;
           res+= (d*(pow(10,mul)));
           mul--;
           n/=10;
        }
        if(res > INT_MAX || res < INT_MIN) return 0;
        if(flag) return res;
        else return res*(-1);
    }
};