class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> maxi;

        for (int i = 0; i < nums.size(); i++) {
            maxi.push(nums[i]);
        }

        for (int i = 1; i < k; i++) {
            maxi.pop();
        }

        return maxi.top();
    }
};