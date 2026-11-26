class Solution {
public:
    bool canAliceWin(int n) {
       
        if(n<10) return false;
        
        int count=0;
        n-=10;
        int x=9;
        while(n>=0){
          n-=x;
          count++;
          x--;
        }
        if(count%2==0)  return false;
        else return true;
       

    }
};