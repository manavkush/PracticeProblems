// https://leetcode.com/problems/design-add-and-search-words-data-structure

class WordDictionary {
vector<WordDictionary*> child;
bool end;
public:
    WordDictionary() {
        child.assign(26, nullptr);
        end = 0;
    }
    
    void addWord(string word) {
        WordDictionary * node = this;
        for(auto &x: word) {
            if(!node->child[x-'a']) {
                node->child[x-'a'] = new WordDictionary();
            }
            node = node->child[x-'a'];
        }
        node->end = 1;
    }
    
    bool search(string &word, int idx, WordDictionary* node) {
        if(idx==word.size())
            return node->end;
        bool ans = false;
        char x = word[idx];
        if(x=='.') {
            for(int i=0;i<26;i++) {
                if(node->child[i])
                    ans |= search(word, idx+1, node->child[i]);
            }
        } else {
            if(!node->child[x-'a'])
                return false;
            ans |= search(word, idx+1, node->child[x-'a']);
        }
        return ans;
    }
    
    bool search(string word) {
        WordDictionary * node = this;
        return search(word, 0, this);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */