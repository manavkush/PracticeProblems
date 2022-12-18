// https://leetcode.com/problems/palindrome-partitioning

class Solution {
private: 
    void util(string &s, vector<vector<string>> &ans, int idx, vector<string> &curr) {
        if(idx == s.length()) {
            ans.push_back(curr);
            return;
        } 
        for(int i=idx;i<s.length();i++) {
            int len = i-idx+1;
            string s1 = s.substr(idx, len);
            string s2 = s1;
            // cout<<idx<<" "<<i<<endl;
            // cout<<s1<<" "<<s2<<endl;

            reverse(s1.begin(), s1.end());
            
            if(s1==s2) {
                curr.push_back(s2);
                util(s, ans, i+1, curr);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        util(s, ans, 0, curr);
        return ans;
    }
};