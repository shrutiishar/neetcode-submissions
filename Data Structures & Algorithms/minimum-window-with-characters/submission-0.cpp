#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> countT, window;

        
        for (char c : t) {
            countT[c]++;
        }

        int have = 0;
        int need = countT.size();

        int l = 0;
        int minLen = INT_MAX;
        int start = 0;

       
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            
            while (have == need) {

               
                if ((r - l + 1) < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                char leftChar = s[l];
                window[leftChar]--;

                
                if (countT.count(leftChar) && window[leftChar] < countT[leftChar]) {
                    have--;
                }

                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};