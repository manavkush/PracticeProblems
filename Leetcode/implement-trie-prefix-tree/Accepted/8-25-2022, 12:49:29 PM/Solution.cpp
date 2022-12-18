// https://leetcode.com/problems/implement-trie-prefix-tree

class Trie {
private:
    // Trie * root;
    vector<Trie*> links;
    bool end;
public:
    Trie() {
        links.assign(26, nullptr);
        end = 0;
    }
    
    void insert(string word) {
        Trie* node = this;
        for(auto &x: word) {
            if(!node->links[x-'a']) {
                node->links[x-'a'] = new Trie();
            }
            node = node->links[x-'a'];
        }
        node->end = true;
    }
    
    bool search(string word) {
        Trie* node = this;
        for(auto &x: word) {
            if(!node->links[x-'a']) 
                return false;
            node = node->links[x-'a'];
        }
        return node->end;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto &x: prefix) {
            if(!node->links[x-'a'])
                return false;
            node = node->links[x-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */