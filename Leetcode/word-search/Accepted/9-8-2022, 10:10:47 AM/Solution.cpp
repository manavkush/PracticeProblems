// https://leetcode.com/problems/word-search

class Solution {
private:
    vector<int> dr = {1, -1, 0, 0};
    vector<int> dc = {0, 0, 1, -1};
    int n, m;
    bool dfs(vector<vector<char>> &board, int r, int c, string &word, int idx) {
        if(idx==word.length())
            return 1;
        if(board[r][c]!=word[idx])
            return 0;
        char og = board[r][c];
        board[r][c] = '*';
        for(int i=0;i<4;i++) {
            int rr = r + dr[i];
            int cc = c + dc[i];
            if(rr<0 || cc<0 || rr>=n || cc>=m) 
                continue;
            if(dfs(board, rr, cc, word, idx+1))
                return true;
        }
        if(dfs(board, r, c, word, idx+1))
            return true;
        board[r][c] = og;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(dfs(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};