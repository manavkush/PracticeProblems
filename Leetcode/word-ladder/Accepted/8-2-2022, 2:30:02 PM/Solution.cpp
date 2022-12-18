// https://leetcode.com/problems/word-ladder

class Solution {
private:
    int diff(string &a, string &b) {
        int cnt = 0;
        int m = a.length();
        for(int j=0;j<m;j++) {
            if(a[j]!=b[j])
                cnt++;
        }
        return cnt;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = beginWord.length();
        vector<vector<int>> adj(n+2);
        bool found = 0;
        for(int i=0;i<n;i++) {
            if(wordList[i]==endWord) {
                found = i+1;
                break;
            }
        }
        if(!found) {
            return 0;
        }
        for(int i=0;i<n;i++) {
            int cnt1 = diff(beginWord, wordList[i]);
            int cnt2 = diff(endWord, wordList[i]);
            
            if(cnt1 == 1)
                adj[0].push_back(i+1);
            
            // if(cnt2==1)
            //     adj[i+1].push_back(n+1);
        }
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if(diff(wordList[i], wordList[j])==1) {
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        queue<pair<int,int>> q;
        vector<int> vis(n+2, 0);
        vis[0] = 1;

        q.push({0, 1});
        while(!q.empty()) {
            pair<int,int> top = q.front();  q.pop();
            int node = top.first, dis = top.second;
            if(node>0 and wordList[node-1]==endWord)
                return dis;
            for(auto &x: adj[node]) {
                if(!vis[x]) {
                    q.push({x, dis+1});
                    vis[x] = 1;
                }
            }
        }
        return 0;
    }
};