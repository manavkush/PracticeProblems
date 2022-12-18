// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length();
        int ans = 1;
        for(int i=0;i<len;i++) {
            ans+= (columnTitle[i]-'A')*(len-i-1);
        }
        return ans;
    }
};