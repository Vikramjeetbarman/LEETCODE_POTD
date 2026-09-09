class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000) return 0;
        long long ans1=0;
        long long count=0;
        long long k=n;
        while(k>999){
            k= k/1000;
            count++;
        }
        long long Begin=1000;
        long long Multi=1000;
        for(int i=0;i<count;i++){
                if(n<1000*Multi){
                    ans1+= n-(Begin-1);
                    break;
                }
                else{
                ans1+= n-(Begin-1);
                    Begin*=1000;
                    Multi*=1000;
                }
        }
        return ans1;



    }
};