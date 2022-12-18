// https://leetcode.com/problems/numbers-with-same-consecutive-differences

class Solution {
private:
    void util(int n, int k, int curr, set<int> &result) {
        if(n==0) {
            result.insert(curr);
            return;
        }
        int last_dig = curr%10;
        if(last_dig+k<=9) {
            util(n-1, k, curr*10+(last_dig+k), result);
        }
        if(last_dig-k>=0) {
            util(n-1, k, curr*10+(last_dig-k), result);
        }
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        set<int> result;
        for(int i=1;i<=9;i++) {
            util(n-1, k, i, result);
        }
        vector<int> ans;
        for(auto &x: result) {
            ans.push_back(x);
        }
        return ans;
    }
};