class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        vector<int> result;

        for (int right = k - 1; right < nums.size(); right++) {
            vector<int> temp;
            for (int i = left; i <= right; i++) {
                temp.push_back(nums[i]);
            }
            sort(temp.begin(), temp.end());
            result.push_back(temp.back());
            left++;
        }

        return result;
    }
};