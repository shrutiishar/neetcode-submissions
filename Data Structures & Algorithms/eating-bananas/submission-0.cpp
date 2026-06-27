#include <cmath>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int maxi = *max_element(piles.begin(), piles.end());
        int mini = INT_MAX;

        for (int k = 1; k <= maxi; k++) {

            int hours = 0;

            for (int bananas : piles) {
                hours += ceil((double)bananas / k);
            }

            if (hours <= h) {
                mini = min(mini, k);
            }
        }

        return mini;
    }
};