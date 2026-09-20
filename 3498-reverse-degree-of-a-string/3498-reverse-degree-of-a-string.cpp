class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            char c=s[i];
            int letter=c-'a'+1;
            int  letvalrev= 26 - letter +1;
            sum+= letvalrev*(i+1);
        }
        return sum;
    }
};