class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int hours = 0;

            for (int bananas : piles) {
                hours += ceil((double)bananas / mid);
            }

            if (hours <= h) {
                ans = mid;          // possible answer
                high = mid - 1;     // try smaller speed
            }
            else {
                low = mid + 1;      // increase speed
            }
        }

        return ans;
    }
};