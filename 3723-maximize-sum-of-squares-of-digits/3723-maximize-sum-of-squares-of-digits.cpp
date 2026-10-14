class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        while(sum!=0){
            if(sum<10){
                ans+=to_string(sum);
                sum-=sum;
            }
            else{
                ans+='9';
                sum-=9;
            }
            num--;
        }
        if(num<0) return "";
        string str(num,'0');
        return ans+str;


    }
};