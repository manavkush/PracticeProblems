// https://leetcode.com/problems/excel-sheet-column-number

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int len = columnTitle.length();
        int ans = 1;
        for(int i=0;i<len;i++) {
            if(i!=len-1)
                ans+=pow(26, i+1);
            ans+= (columnTitle[i]-'A')*(len-i);
        }
        return ans;
    }
};