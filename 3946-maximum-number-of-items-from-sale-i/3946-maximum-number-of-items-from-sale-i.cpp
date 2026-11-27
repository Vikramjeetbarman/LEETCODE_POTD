class Solution {
    int dp[1001][1501];

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int cheapestItem = INT_MAX;
        vector<int> copies(n, 0);

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++) {
            cheapestItem = min(cheapestItem, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i == j) continue;

                if (items[j][0] % items[i][0] == 0) {
                    copies[i]++;
                }
            }
        }

        return helper(n, items, budget, cheapestItem, copies);
    }

    int helper(int n, vector<vector<int>>& items, int budget,
        int cheapestItem, vector<int>& copies) {

        if (n == 0) return budget / cheapestItem;

        if (dp[n][budget] != -1) return dp[n][budget];

        int take = 0;

        if (items[n - 1][1] <= budget) {
            take = 1 + copies[n - 1] + helper(n - 1, items, budget - items[n - 1][1], cheapestItem, copies);
        }

        int notTake = helper(n - 1, items, budget, cheapestItem, copies);

        return dp[n][budget] = max(take, notTake);
    }
};