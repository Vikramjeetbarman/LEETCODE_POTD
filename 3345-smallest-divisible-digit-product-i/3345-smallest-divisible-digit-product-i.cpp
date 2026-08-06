class Solution {
public:
   
    int smallestNumber(int n, int t) {
        int ans=0;
        for(int i=n;i<=100;i++){
            if(i<10){
                if(i%t==0){
                    ans=i;
                break;
                }
                continue;
            }
            int k=i;
            int d=k%10;
            int d2=k/10;
            int d3=0;
            int d4=0;
            if(d2>9){
                d3=d2%10;
                d4=d2/10;
                if((d4*d3*d)%t==0){
                 ans=i;
                 break;
                }
            }
            else{
            if((d2*d)%t==0) {
            ans=i;
            break;
            }

            }
        }
        return ans;
    }
};