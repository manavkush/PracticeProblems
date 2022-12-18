// https://leetcode.com/problems/palindrome-pairs

vector<vector<int>> result;
class Solution {
class Trie {
    vector<Trie*> child;
    int end;
    public:
    
    Trie() {
        child.assign(26, nullptr);
        end = -1;
    }
    
    // Insert
    void insert(string &s, int idx) {
        Trie* node = this;
        for(int i=0;i<s.length();i++) {
            int letter = s[i]-'a';
            if(node->child[letter]==nullptr) {
                node->child[letter] = new Trie();
            }
            node = node->child[letter];
        }
        node->end = idx;
    }
    
    // DFS
    void dfs(Trie* node, string &curr, int idx) {
        if(!node) {
            return;
        }
        if(node->end!=-1) {
            string rev = curr;
            reverse(rev.begin(), rev.end());
            if(rev==curr and node->end != idx) {
                // cout<<node->end<<" "<<idx<<endl;
                vector<int> temp = {node->end, idx};
                result.push_back(temp);
            }
        }
        for(int i=0;i<26;i++) {
            curr += ('a'+i);
            dfs(node->child[i], curr, idx);
            curr.pop_back();
        }
    }
    
    // Calculate
    void calc(string &s, int idx) {
        Trie* node = this;
        {
            string rev = s;
            reverse(rev.begin(), rev.end());
            if(s==rev and node->end!=-1 and node->end!=idx) {
                result.push_back({node->end, idx});
            }
        }
        for(int i=0;i<s.length();i++) {
            int letter = s[i]-'a';
            if(node->child[letter]==nullptr) {
                string left = s.substr(i);
                string rev = left;
                reverse(rev.begin(), rev.end());
                if(left==rev and node->end!=-1) {
                    result.push_back({node->end, idx});
                }
                return;
            }
            node = node->child[letter];
        }
        
        string curr;
        dfs(node, curr, idx);
    }
};
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        Trie trie;
        for(int i=0;i<words.size();i++) {
            trie.insert(words[i], i);
        }
        result.clear();
        for(int i=0;i<words.size();i++) {
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            trie.calc(rev, i);
        }
        return result;
    }
};