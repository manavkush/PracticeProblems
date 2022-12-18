// https://leetcode.com/problems/prefix-and-suffix-search


class WordFilter {
    vector<WordFilter*> child;
    int index;
public:
    WordFilter() {
        child.assign(27, nullptr);
    }
    
    WordFilter(vector<string>& words) {
        child.assign(27, nullptr);
        for(int j=0;j<words.size();j++) {
            string x = words[j] + "{" + words[j];
            int n = words[j].length();
            for(int i=0;i<n;i++) {
                string sub = x.substr(i);
                insert(sub, j);
            }
        }
    }
    
    void insert(string str, int idx) {
        WordFilter * node = this;
        for(auto &c: str) {
            if(node->child[c-'a']==nullptr) {
                node->child[c-'a'] = new WordFilter();
            }
            node = node->child[c-'a'];
            node->index = idx;
        }
        
    }
    
    int find(string &str) {
        WordFilter* node = this;
        for(auto &c: str) {
            if(node->child[c-'a']==nullptr) {
                return -1;
            } 
            node = node->child[c-'a'];
        }
        return node->index;
    }
    
    int f(string pref, string suff) {
        string to_find = suff + '{' + pref;
        // return -1;
        return find(to_find);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */