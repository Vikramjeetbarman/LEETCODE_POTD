class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, '.' + string(n - 1, '#')); 
        grid[m-1] = string(n, '.');  
        return grid;
    }
};