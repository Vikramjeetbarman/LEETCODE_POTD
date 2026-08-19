class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int ,unordered_set<int>> mp;
        for(auto &reservedSeat: reservedSeats){
            int row=reservedSeat[0];
            int seat=reservedSeat[1];
            mp[row].insert(seat);    
    }
    long long ans=(n-mp.size())*2;
    for(auto &[row,seat]:mp){
          auto isAvailable=[&](int num){
               return seat.find(num)==seat.end();
          };
          bool g1=isAvailable(2) && isAvailable(3)&&isAvailable(4)&&isAvailable(5);
          bool g2=isAvailable(6) && isAvailable(7)&&isAvailable(4)&&isAvailable(5);
          bool g3=isAvailable(6) && isAvailable(7)&&isAvailable(8)&&isAvailable(9);
          if(g1 && g3) ans+=2;
          else if(g1||g2||g3){
            ans++;
          }
    }
    return ans;
          
    }
};