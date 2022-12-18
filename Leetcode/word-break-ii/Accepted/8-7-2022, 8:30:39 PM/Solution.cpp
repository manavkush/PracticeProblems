// https://leetcode.com/problems/word-break-ii

class Solution {
private:
    void util(string &s, unordered_map<string,int> &hash, int i, vector<string> &ans, string &curr) {
        int n = s.length();
        if(i==n) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        int len = curr.length();
        string temp;
        
        for(int mid=i;mid<n;mid++) {
            temp += s[mid];
            if(hash.find(temp)!=hash.end()) {
                curr += (temp + " ");
                util(s, hash, mid+1, ans, curr);
                curr = curr.substr(0, len);
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> ans;
        int n = s.length();
        unordered_map<string, int> hash;
        for(auto &x: wordDict) {
            hash[x]++;
        }
        string curr;
        util(s, hash, 0, ans, curr);
        return ans;
    }
};