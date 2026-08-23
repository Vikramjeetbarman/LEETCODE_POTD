class Solution {
public:
    string largestNumber(vector<int>& nums) {
         vector<string> a;        
         for(int n:nums)
         a.push_back(to_string(n));
         sort(a.begin(),a.end(),[](string a, string b){  // lambda lagaye hai
            return a+b>b+a;
        });
        
        if(a[0]=="0")
            return "0";
        
        string result = "";
        for(string s:a)
            result+=s;
        
        return result;
    }
};