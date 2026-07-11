#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[10001][13];
    const int INF = 1e9;

    int solve(vector<int>& coins, int amount, int n) {
        if (amount == 0)
            return 0;

        if (n == 0)
            return INF;

        if (dp[amount][n] != -1)
            return dp[amount][n];

        if (coins[n - 1] <= amount) {
            return dp[amount][n] = min(
                1 + solve(coins, amount - coins[n - 1], n),
                solve(coins, amount, n - 1)
            );
        }
        else {
            return dp[amount][n] = solve(coins, amount, n - 1);
        }
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        memset(dp, -1, sizeof(dp));

        int ans = solve(coins, amount, n);

        if (ans >= INF)
            return -1;

        return ans;
    }
};