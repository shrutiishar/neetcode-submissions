#include<cstring>
class Solution {
public:
    int dp[1001];

    int solve(vector<int>& cost, int i) {
        if (i == 0) return cost[0];
        if (i == 1) return cost[1];

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = cost[i] + min(solve(cost, i - 1),
                                     solve(cost, i - 2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));

        int n = cost.size();

        return min(solve(cost, n - 1),
                   solve(cost, n - 2));
    }
};