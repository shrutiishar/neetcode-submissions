
#include<cstring>
class Solution {
public:
    int dp[1001];

    int houserob(vector<int>& nums, int n) {

        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int take = nums[n - 1] + houserob(nums, n - 2);
        int not_take = houserob(nums, n - 1);

        return dp[n] = max(take, not_take);
    }

    int rob(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        int n = nums.size();

        return houserob(nums, n);
    }
};