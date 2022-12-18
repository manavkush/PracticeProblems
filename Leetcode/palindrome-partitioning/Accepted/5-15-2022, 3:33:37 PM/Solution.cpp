// https://leetcode.com/problems/palindrome-partitioning

class Solution {
private: 
    bool is_palindrome(string &s, int start, int end) {
        while(start<end) {
            if(s[start]!=s[end]) return false;
            
            start++;
            end--;
        }
        return true;
    }
    
    void util(string &s, vector<vector<string>> &ans, vector<string> &curr, int idx ) {
        if(idx == s.length()) {
            ans.push_back(curr);
            return;
        } 
        for(int i=idx;i<s.length();i++) {
            int len = i-idx+1;
            
            if(is_palindrome(s, idx, i)) {
                curr.push_back(s.substr(idx,i-idx+1));
                util(s, ans, curr,i+1);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        util(s, ans, curr,0);
        return ans;
    }
};