class Solution {
public:
    bool checkString(string s) {
        string k=s;
        sort(k.begin(),k.end());
        if(k==s) return true;
        else return false;
    }
};