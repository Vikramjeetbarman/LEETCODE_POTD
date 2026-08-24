class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        sort(begin(s),end(s));
        sort(begin(t),end(t));
        if(s==t) return true;
        else return false;
    }
};