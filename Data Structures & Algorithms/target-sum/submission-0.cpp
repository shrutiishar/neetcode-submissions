class Solution {
public:
    int target;

    int solve(vector<int>& nums, int sum, int n) {
        if (n == 0) {
            if (sum == target)
                return 1;
            return 0;
        }

        return solve(nums, sum + nums[n - 1], n - 1) +
               solve(nums, sum - nums[n - 1], n - 1);
    }

    int findTargetSumWays(vector<int>& nums, int t) {
        target = t;
        return solve(nums, 0, nums.size());
    }
};
