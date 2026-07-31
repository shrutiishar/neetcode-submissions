#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> need;
        unordered_map<char, int> window;

        // Build need map
        for (int i = 0; i < t.size(); i++) {
            need[t[i]]++;
        }

        int required = need.size();
        int matched = 0;

        int left = 0;
        int minlen = INT_MAX;
        int start = 0;

        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];
            window[ch]++;

            if (need.count(ch) && need[ch] == window[ch]) {
                matched++;
            }

            while (matched == required) {

                if (right - left + 1 < minlen) {
                    minlen = right - left + 1;
                    start = left;
                }

                char chleft = s[left];

                if (need.count(chleft) &&
                    need[chleft] == window[chleft]) {
                    matched--;
                }

                window[chleft]--;
                left++;
            }
        }

        if (minlen == INT_MAX) {
            return "";
        }

        return s.substr(start, minlen);
    }
};