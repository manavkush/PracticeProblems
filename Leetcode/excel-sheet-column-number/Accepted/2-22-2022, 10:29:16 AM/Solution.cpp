// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length();
        int ans = 0;
        for(int i=0;i<len;i++) {
            ans += (columnTitle[i]-'A'+1)* pow(26, len-i-1);
        }
        return ans;
    }
};