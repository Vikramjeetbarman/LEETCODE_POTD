class Solution {
public:
  typedef long long ll;
  ll digitsum(int n){
       ll sum=0;
      while(n>0){
        ll k=n%10;
          sum+=k;
          n/=10;
      }
      return sum;
  }
  ll digitprod(int n){
      ll sum=1;
      while(n>0){
          ll k=n%10;
          sum*=k;
          n/=10;
      }
      return sum;
  }
    bool checkDivisibility(int n) {
        ll sum=digitprod(n)+digitsum(n);
         if(n%sum==0) return true;
         else return false;
    }
};