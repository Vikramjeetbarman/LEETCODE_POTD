class Solution {
public:
    long long minimumCost(long long cost1, long long cost2, long long costBoth, long long need1, long long need2) {
        if(need1==0 && need2==0) return 0;
         long long finalans1= cost1*need1 + cost2*need2;
         long long finalans2= max(need1,need2)*costBoth;
         long long finalans3=0;
         if(finalans3==0){
            finalans3+= need1*costBoth;
            if(need1>=need2){
                finalans3+=0;
            }
            else finalans3+=(need2-need1)*cost2;
         }
         long long finalans4=0;
         if(finalans4==0){
            finalans4+= need2*costBoth;
            if(need2>=need1){
                finalans4+=0;
            }
            else finalans4+=(need1-need2)*cost1;
         }
         long ans= min(finalans1, min(finalans2,min(finalans3,finalans4)));return ans;
          
    }
};