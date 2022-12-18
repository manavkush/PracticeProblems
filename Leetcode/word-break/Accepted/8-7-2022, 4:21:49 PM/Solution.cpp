// https://leetcode.com/problems/word-break

class Solution {
private:
    int util(vector<int> &dp, string s, unordered_map<string,int> &hash, int i) {
        int n = s.length();
        if(i<0)
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans = 0;
        for(int mid=i;mid>=0;mid--) {
            string sub = s.substr(mid, i-mid+1);
            if(hash.find(sub)!=hash.end()) {
                ans |= util(dp, s, hash, mid-1);
            }
        }
        dp[i] = ans;
        return dp[i];
    }
public:
    int wordBreak( string s, vector<string>& wordDict) {
        unordered_map<string,int> hash;
        for(auto &x: wordDict) {
            hash[x]++;
        }
        int n = s.length();
        vector<int> dp(n+1, -1);
        return util(dp,s, hash, n-1);
    }
};