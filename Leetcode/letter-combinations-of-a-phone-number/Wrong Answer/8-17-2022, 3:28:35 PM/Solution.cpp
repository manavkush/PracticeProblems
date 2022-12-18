// https://leetcode.com/problems/letter-combinations-of-a-phone-number

class Solution {
private:
    void util(int idx, string &digits, unordered_map<int,vector<char>> &hash, string &curr, vector<string> &ans) {
        if(idx==digits.length()) {
            ans.push_back(curr);
            return;
        }
        for(auto &x: hash[digits[idx]-'0']) {
            curr+=x;
            util(idx+1, digits, hash, curr, ans);
            curr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<int,vector<char>> hash;
        hash[2] = {'a', 'b', 'c'};
        hash[3] = {'d', 'e', 'f'};
        hash[4] = {'g', 'h', 'i'};
        hash[5] = {'j', 'k', 'l'};
        hash[6] = {'m', 'n', 'o'};
        hash[7] = {'p', 'q', 'r', 's'};
        hash[8] = {'t', 'u', 'v'};
        hash[9] = {'w', 'x', 'y', 'z'};
        
        vector<string> ans;
        string curr;
        util(0, digits, hash, curr, ans);
        return ans;
    }
};