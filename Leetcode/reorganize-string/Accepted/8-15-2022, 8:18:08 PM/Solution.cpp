// https://leetcode.com/problems/reorganize-string

class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        if(n==1)
            return s;
        bool flag = 0;
        priority_queue<pair<int,int>> pq;
        vector<int> freq(26, 0);
        for(int i=0;i<n;i++) {
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++) {
            if(freq[i])
                pq.push({freq[i], i});
        }
        string ans;
        while(!pq.empty()) {
            if(pq.size()==1) {
                if(pq.top().first==1) {
                    ans += 'a'+pq.top().second;
                    return ans;
                } else {
                    return "";
                }
            } else {
                auto top = pq.top(); pq.pop();
                auto top2 = pq.top(); pq.pop();
                ans += 'a'+top.second;
                ans += 'a'+top2.second;
                
                if(top.first>1)
                    pq.push({top.first-1, top.second});
                if(top2.first>1) {
                    pq.push({top2.first-1, top2.second});
                }
            }
        }
        return ans;
    }
};