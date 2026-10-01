class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ele : s){
            if(ele=='(' || ele=='{' || ele=='[') st.push(ele);
            else{
                if(st.empty()) return false;
                char ch=st.top();
                st.pop();
                if((ele==')' && ch!='(') || (ele==']' && ch!='[') || (ele=='}' && ch!='{')){
                    return false;
                }
            }
        }
        return st.empty();   
    }
};