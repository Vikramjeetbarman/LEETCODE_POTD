class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool flag=false;
        if(rec1[0]<=rec2[0] && rec2[0]<rec1[2]){
            if(rec1[1]<rec2[3] && rec2[1]<rec1[3])
                flag=true;
        }

        if(rec2[0]<=rec1[0] && rec1[0]<rec2[2]){
            if(rec2[1]<rec1[3] && rec1[1]<rec2[3])
                flag=true;
        }
        return flag;
    }
};