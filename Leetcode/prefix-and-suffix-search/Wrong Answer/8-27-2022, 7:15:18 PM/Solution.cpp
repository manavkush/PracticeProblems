// https://leetcode.com/problems/prefix-and-suffix-search


class WordFilter {
    unordered_map<string,WordFilter*> child;
    int end;
    int index;
public:
    WordFilter() {
        index=-2;
    }
    WordFilter(vector<string>& words) {
        
        for(int j=0;j<words.size();j++) {
            WordFilter * node = this;
            string x = words[j];
            int n = x.length();
            for(int i=0;i<n;i++) {
                string temp;
                temp += x[i];
                temp += x[n-1-i];
                if(node->child.find(temp)==node->child.end()) {
                    node->child[temp] = new WordFilter();
                }
                // cout<<temp<<" "<<j<<endl;
                node = node->child[temp];
                node->index = j;
            }
        }
    }
    
    int util(WordFilter* node, string &pref, string &suff, int i, int f) {
        int n = pref.length();
        int m = suff.length();
        
        if(i==n and f==m) {
            return node->index;   
        } else if(i!=n and f!=m) {
            string temp;
            temp += pref[i];
            temp += suff[f];
            if(node->child.find(temp)==node->child.end()) {
                // cout<<"*"<<temp;
                return -1;
            } else {
                // cout<<"#"<<temp<<node->child[temp]->index;
                return util(node->child[temp], pref, suff, i+1, f+1);
            }
        } else if(i==n) {
            for(auto &x: node->child) {
                string key = x.first;
                if(key[1]==suff[f]) {
                    return util(x.second, pref, suff, i, f+1);
                }
            }
            return -1;
        } else {
            for(auto &x: node->child) {
                string key = x.first;
                if(key[0]==pref[i]) {
                    return util(x.second, pref, suff, i+1, f);
                }
            }
            return -1;
        }
    }
    
    int f(string pref, string suff) {
        WordFilter * node = this;
        // cout<<child["aa"]->index;
        reverse(suff.begin(), suff.end());
        return util(node, pref, suff, 0, 0);
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */