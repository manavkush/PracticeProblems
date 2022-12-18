// https://leetcode.com/problems/partition-labels

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        vector<vector<int>> hash(26);
        for(int i=0;i<n;i++) {
            hash[s[i]-'a'].push_back(i);
        }
        int prev = 0;
        int curr = 0;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            curr++;
            prev = max(prev, hash[s[i]-'a'].back());
            if(i==prev) {
                ans.push_back(curr);
                prev = i+1;
                curr=0;
            }
            
        }
        // ans.push_back(curr);
        return ans;
    }
};