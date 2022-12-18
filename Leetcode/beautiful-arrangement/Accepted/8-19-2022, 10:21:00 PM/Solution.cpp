// https://leetcode.com/problems/beautiful-arrangement

class Solution {
private:
    int util(int n , vector<int> &curr, int idx, vector<vector<int>> &pos) {
        if(idx>n)
            return 1;
        int ans = 0;
        for(auto &x: pos[idx]) {
            if(curr[x]==-1) {
                curr[x] = idx;
                ans += util(n, curr, idx+1, pos);
                curr[x] = -1;
            }
        }
        return ans;
    }
public:
    int countArrangement(int n) {
        vector<int> curr(n+1, -1);
        vector<vector<int>> pos(n+1);
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i%j==0 || j%i==0) {
                    pos[i].push_back(j);
                }
            }
        }
        return util(n, curr, 1, pos);
        
    }
};