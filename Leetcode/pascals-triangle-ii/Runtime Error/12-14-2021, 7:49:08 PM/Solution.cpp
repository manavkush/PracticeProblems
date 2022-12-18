// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        int curr = 1;
        ans[0] = ans[rowIndex] = 1;
        for(int i=1;i<rowIndex;i++) {
            curr = curr*(rowIndex-i+1)/(i);
            ans[i] = curr;
        }
        return ans;
    }
};