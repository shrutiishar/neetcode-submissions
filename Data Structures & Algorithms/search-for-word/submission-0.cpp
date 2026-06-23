class Solution {
public:

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int idx) {

        if (idx == word.size())
            return true;

        if (i < 0 || j < 0 ||
            i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';   // mark visited

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (dfs(board, word, ni, nj, idx + 1))
                return true;
        }

        board[i][j] = temp;  // backtrack
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};