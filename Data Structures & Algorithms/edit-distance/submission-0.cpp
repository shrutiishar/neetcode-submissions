#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[101][101];

    int solve(int i, int j, string& word1, string& word2) {
        
        // word1 khatam ho gaya
        if (i < 0)
            return j + 1;

        // word2 khatam ho gaya
        if (j < 0)
            return i + 1;

        // Already calculated
        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters same -> koi operation nahi
        if (word1[i] == word2[j]) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2);
        }

        // Characters different

        // Delete word1[i]
        int del = solve(i - 1, j, word1, word2);

        // Insert word2[j]
        int ins = solve(i, j - 1, word1, word2);

        // Replace word1[i] with word2[j]
        int rep = solve(i - 1, j - 1, word1, word2);

        return dp[i][j] = 1 + min({del, ins, rep});
    }

    int minDistance(string word1, string word2) {
        
        memset(dp, -1, sizeof(dp));

        return solve(word1.size() - 1,
                     word2.size() - 1,
                     word1,
                     word2);
    }
};

