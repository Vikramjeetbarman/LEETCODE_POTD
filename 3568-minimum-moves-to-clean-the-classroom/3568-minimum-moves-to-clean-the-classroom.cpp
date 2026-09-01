class Solution {
public:
    int minMoves(vector<string>& grid, int energy) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> litterIdx(n,vector<int>(m,-1));
        int lc = 0;
        int si = -1, sj = -1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 'S')
                {
                    si = i;
                    sj = j;
                }
                if(grid[i][j] == 'L') litterIdx[i][j] = lc++;
            }
        }
        int maxMask = 1 << lc;
        int targetMask = maxMask - 1;
        vector<bool> visited(n*m*(energy+1)*maxMask, false);
        auto getIndex = [&](int r,int c,int e,int mask)
        {
            return ((r*m + c) * (energy+1) + e) * maxMask + mask;
        };
        queue<array<int, 4>> q;
        q.push({si, sj, energy, 0});
        visited[getIndex(si, sj, energy, 0)] = true;
        int level = 0;
        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(q.size())
        {
            int sz = q.size();
            while(sz--)
            {
                auto curr = q.front();
                q.pop();
                int i = curr[0], j = curr[1];
                int currEnergy = curr[2];
                int mask = curr[3];
                if(mask == targetMask) return level;
                if(currEnergy == 0) continue;
                for(int d=0;d<4;d++)
                {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if(ni < 0 || nj < 0 || ni >= n || nj >= m || grid[ni][nj] == 'X') continue;
                    int newEnergy = currEnergy - 1;
                    if(grid[ni][nj] == 'R') newEnergy = energy;
                    int newMask = mask;
                    if(grid[ni][nj] == 'L') newMask |= (1 << litterIdx[ni][nj]);
                    if(newEnergy < 0 || visited[getIndex(ni, nj, newEnergy, newMask)]) continue;
                    visited[getIndex(ni, nj, newEnergy, newMask)] = true;
                    q.push({ni, nj, newEnergy, newMask});
                }
            }
            level++;
        }
        return -1;
    }
};