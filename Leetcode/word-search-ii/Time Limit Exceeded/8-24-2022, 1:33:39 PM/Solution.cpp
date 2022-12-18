// https://leetcode.com/problems/word-search-ii

class Solution {

struct Node {
    vector<Node*> links;
    bool end;
    Node() {
        end = false;
        links.assign(26, nullptr);
    }
    bool contains(int letter) {
        return (links[letter]!=nullptr);
    }
    Node* get(int letter) {
        return links[letter];
    }
    void put(int letter, Node* temp) {
        links[letter] = temp;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string str) {
        Node *node = root;
        int len = str.length();
        for(auto &x: str) {
            int letter = x-'a';
            if(!node->contains(letter)) {
                node->put(letter, new Node());
            } 
            node = node->get(letter);
        }
        node->end = true;
    }
    bool check(string str) {
        Node *node = root;
        int len = str.length();
        for(auto &x: str) {
            int letter = x-'a';
            if(!node->contains(letter)) {
                return false;
            }
            node = node->get(letter);
        }
        return node->end;
    }
};

bool check(vector<vector<char>> &board, set<pair<int,int>> &vis, int r, int c) {
    int n = board.size(), m = board[0].size();
    if(r<0 || c<0 || r>=n || c>=m || vis.find({r,c})!=vis.end()) {
        return false;
    }
    return true;
}

set<string> st;
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void dfs(vector<vector<char>>& board, set<pair<int,int>> &vis, int r, int c, string &curr, Trie &trie) {
    curr += board[r][c];
    vis.insert({r, c});
    if(trie.check(curr)) {
        st.insert(curr);
    }
    if(curr.length()<10) {
        for(int dir=0;dir<4;dir++) {
            int rr = r+dr[dir];
            int cc = c+dc[dir];
            if(check(board, vis, rr, cc)) {
                dfs(board, vis, rr, cc, curr, trie);
            }
        }
    }
    vis.erase({r,c});
    curr.pop_back();
}
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {        
        
        int n = board.size();
        int m = board[0].size();
        
        Trie trie;
        for(auto &word: words) {
            trie.insert(word);
        }
        set<pair<int,int>> vis;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                string curr;
                dfs(board, vis, i, j, curr, trie);
            }
        }
        vector<string> ans;
        for(auto &x: st) {
            ans.push_back(x);
        }
        return ans;
    }
};