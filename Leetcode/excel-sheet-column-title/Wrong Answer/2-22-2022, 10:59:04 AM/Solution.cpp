// https://leetcode.com/problems/excel-sheet-column-title

class Solution {
public:
    string convertToTitle(int num) {
        string ans;
        while(num>0) {
            int c = num%26;
            num /= 26;
            char ch;
            if(c==0) {
                ch = 'Z';
            } else {
                ch = 'A' + c-1;
            }
            ans+= ch;
        }
        return ans;
    }
};