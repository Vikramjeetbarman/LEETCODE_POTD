class Solution{
    public:
      struct Node {
        int pre = 0; 
        int suf = 0;
        int maxLen = 0;
        char leftChar = 0;
        char rightChar = 0;
    };

    int n;
    vector<Node> segTree;

    Node merge(const Node& L, const Node& R, int leftLen, int rightLen){
        Node res;

        res.leftChar  = L.leftChar;
        res.rightChar = R.rightChar;

        res.pre = L.pre;
        if (L.pre == leftLen && L.rightChar == R.leftChar) {
            res.pre = L.pre + R.pre;
        }

        res.suf = R.suf;
        if (R.suf == rightLen && L.rightChar == R.leftChar) {
            res.suf = R.suf + L.suf;
        }

        res.maxLen = max(L.maxLen, R.maxLen);
        if (L.rightChar == R.leftChar) {
            res.maxLen = max(res.maxLen, L.suf + R.pre);
        }

        return res;
    }

    void buildSegmentTree(int i, int l, int r, string& s) {
        if (l == r) {
            segTree[i] = { 1, 1, 1, s[l], s[l] };
            return;
        }
        int mid = l + (r - l) / 2;
        buildSegmentTree(2 * i + 1, l, mid, s);
        buildSegmentTree(2 * i + 2, mid + 1, r, s);
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    void update(int i, int l, int r, int pos, char ch) {
        if (l == r) { //l == r == pos
            segTree[i] = { 1, 1, 1, ch, ch };
            return;
        }
        int mid = l + (r - l) / 2;
        if (pos <= mid) {
            update(2 * i + 1, l, mid, pos, ch);
        } else {
            update(2 * i + 2, mid + 1, r, pos, ch);
        }
        segTree[i] = merge(segTree[2 * i + 1], segTree[2 * i + 2], mid - l + 1, r - mid);
    }

    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        n = s.size();
        segTree.assign(4 * n, Node()); //segmen tree size 4*n

        buildSegmentTree(0, 0, n - 1, s);

        int k = queryIndices.size();

        vector<int> result(k);
        for (int i = 0; i < k; i++) {
            int pos = queryIndices[i];
            char ch = queryCharacters[i];
            update(0, 0, n - 1, pos, ch);
            
            result[i] = segTree[0].maxLen;
        }
        return result;
        }
    
    
};
//Approach (Segment Tree)  
    
//brute force
// class Solution {
// public:
//     int search(string a){
//         int n=a.length();
//         int len=1;
//         int maxlen=1;
//         for(int i=0;i<n-1;i++){
//             if(a[i]==a[i+1]){
//                 len++;
//             }
//             else{
//                 maxlen=max(len,maxlen);
//                 len=1;
//             }
//         }
//         maxlen=max(len,maxlen);
//         return maxlen;
//     }
//     vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices){
//         int k=queryIndices.size();
//         int maxlength=0;
//         vector<int > ans;
//         for(int i=0;i<k;i++){
//             s[queryIndices[i]]=queryCharacters[i];
//             int num=search(s);
//             ans.push_back(num);
//             maxlength=max(maxlength,num);
//         }
//         return ans;
        
//     }
// };