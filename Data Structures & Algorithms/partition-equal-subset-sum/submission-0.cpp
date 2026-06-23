#include <cstring>

class Solution {
public:
    int dp[1001][1001];

    bool solve(vector<int>& nums, int sum, int n) {
        if(sum == 0)
            return true;

        if(n == 0)
            return false;

        if(dp[n][sum] != -1)
            return dp[n][sum];

        if(nums[n-1] <= sum) {
            return dp[n][sum] =
                solve(nums, sum - nums[n-1], n-1) ||
                solve(nums, sum, n-1);
        }

        return dp[n][sum] = solve(nums, sum, n-1);
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        int sum = 0;
        for(int x : nums)
            sum += x;

        if(sum % 2 != 0)
            return false;

        return solve(nums, sum/2, nums.size());
    }
};