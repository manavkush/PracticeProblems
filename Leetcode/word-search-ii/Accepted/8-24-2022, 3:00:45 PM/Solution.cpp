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
    public:
        Node* root;
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
};

bool check(vector<vector<char>> &board, int r, int c) {
    int n = board.size(), m = board[0].size();
    if(r<0 || c<0 || r>=n || c>=m || board[r][c]=='*') {
        return false;
    }
    return true;
}

unordered_set<string> st;
vector<int> dr = {1, -1, 0, 0};
vector<int> dc = {0, 0, 1, -1};

void dfs(vector<vector<char>>& board, int r, int c, string &curr, Node* node) {
    int letter = board[r][c]-'a';
    if(!node->contains(letter)) {
        return;
    }
    curr += board[r][c];
    
    node = node->get(letter);
    
    if(node->end) {
        st.insert(curr);
    }
    
    char orignal = board[r][c];
    board[r][c] = '*';
    
    for(int dir=0;dir<4;dir++) {
        int rr = r+dr[dir];
        int cc = c+dc[dir];
        if(check(board, rr, cc)) {
            dfs(board, rr, cc, curr, node);
        }
    }
    
    board[r][c] = orignal;
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
        
        string curr;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dfs(board, i, j, curr, trie.root);
            }
        }
        
        vector<string> ans;
        for(auto &x: st) {
            ans.push_back(x);
        }
        return ans;
    }
};