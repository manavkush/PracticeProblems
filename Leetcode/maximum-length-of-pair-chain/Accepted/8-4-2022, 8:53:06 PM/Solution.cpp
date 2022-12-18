// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
private:
    int util(vector<int> &dp, vector<pair<int,int>> &vec, int idx) {
        int n = vec.size();
        if(idx>=n)
            return 0;
        int curr = 0;
        if(dp[idx]!=-1) 
            return dp[idx];
        for(int i=idx+1; i<n;i++) {
            if(vec[i].first>vec[idx].second) {
                curr = max(curr, 1 + util(dp,vec, i));
            }
        }
        return dp[idx] = curr;
    }
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        vector<pair<int,int>> vec;
        int n = pairs.size();
        for(int i=0;i<n;i++) {
            vec.push_back({pairs[i][0], pairs[i][1]});
        }
        sort(vec.begin(), vec.end());
        vector<int> dp(n+1, -1);
        vec.insert(vec.begin(), {INT_MIN, INT_MIN});
        return util(dp, vec, 0);
    }
};