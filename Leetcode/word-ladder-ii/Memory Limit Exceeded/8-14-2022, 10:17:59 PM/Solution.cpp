// https://leetcode.com/problems/word-ladder-ii

class Solution {
private:
    bool diff(string &a, string &b) {
        int len = a.length();
        int cnt = 0;
        for(int i=0;i<len;i++) {
            if(a[i]!=b[i])
                cnt++;
        }
        return cnt==1;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<int,int> vis;
        unordered_map<int,int> vis2;
        
        vector<vector<string>> ans;
        queue<vector<string>> q;
        
        
        if(st.find(endWord)==st.end()) {
            return ans;
        }
        // REMOVING DUPLICATE OF beginWord
        wordList.insert(wordList.begin(), beginWord);
        for(int i=1;i<wordList.size();i++) {
            if(wordList[i]==wordList[0]) {
                wordList[i] = wordList.back();
                wordList.pop_back();
                break;
            }
        }
        
        int n = wordList.size();
        
        unordered_map<string, int> pos;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++) {
            pos[wordList[i]] = i;
        }
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(diff(wordList[i], wordList[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        q.push({beginWord});
       
        while(!q.empty()) {
            int sz = q.size();
            bool found = 0;
            for(int i=0;i<sz;i++) {
                vector<string> top = q.front(); q.pop();
                string last = top.back();
                if(last==endWord) {
                    ans.push_back(top);
                    found = 1;
                } else {
                    for(auto &x : adj[pos[last]]) {
                        if(vis.find(x)==vis.end()) {
                            top.push_back(wordList[x]);
                            q.push(top);
                            top.pop_back();
                            vis2[x]++;
                        }
                    }
                }
            }
            if(found) {
                break;
            }
            for(auto &x: vis2) {
                vis[x.first]++;
            }
            vis2.clear();
        }
        return ans;
    }
};