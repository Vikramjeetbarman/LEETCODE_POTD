class Solution {
public:
    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int i = 0;

        while (i + k <= n) {
            bool isLenK = isPalindrome(s, i, i + k - 1);
            bool isLenKPlus1 = (i + k < n) && isPalindrome(s, i, i + k);

            if (isLenK) {
                count++;
                i += k;
            } 
            else if (isLenKPlus1) {
                count++;
                i += k + 1;
            } 
            else {
                i++;
            }
        }

        return count;
    }
};