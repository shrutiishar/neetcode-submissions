#include <cstring>
using namespace std;

class Solution {
public:
    int dp[105];

    int solve(int i, int start, vector<int>& nums) {
        if (i < start)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // Don't rob current house
        int skip = solve(i - 1, start, nums);

        // Rob current house
        int rob = nums[i] + solve(i - 2, start, nums);

        return dp[i] = max(skip, rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: houses [0 ... n-2]
        memset(dp, -1, sizeof(dp));
        int case1 = solve(n - 2, 0, nums);

        // Case 2: houses [1 ... n-1]
        memset(dp, -1, sizeof(dp));
        int case2 = solve(n - 1, 1, nums);

        return max(case1, case2);
    }
};
