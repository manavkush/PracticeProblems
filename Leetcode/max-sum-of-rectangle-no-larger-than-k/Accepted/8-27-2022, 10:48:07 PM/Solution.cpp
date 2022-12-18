// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int ans = INT_MIN;
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int l=0;l<cols;l++) {
            vector<int> sums(rows,0);
            for(int r = l; r<cols;r++) {
                for(int row=0;row<rows;row++) {
                    sums[row]+=matrix[row][r];
                }
                // added sum of 1 column to total
                int curr = 0;
                set<int> st = {0};
                for(auto &x: sums) {
                    curr += x;
                    auto pos = st.lower_bound(curr - k);
                    if(pos!=end(st)) {
                        ans = max(ans, curr-(*pos));
                    }
                    st.insert(curr);
                }
            }
        }
        return ans;
    }
};