#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        
        int longest = 0;

        for (int num : s) {
            // start only if previous element not present
            if (s.find(num - 1) == s.end()) {
                int curr = num;
                int count = 1;

                // move forward in sequence
                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};