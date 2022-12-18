// https://leetcode.com/problems/strictly-palindromic-number

class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        
        for(int i=2;i<=n-2;i++) {
            int num = n;
            string str;
            while(num) {
                str += to_string(num%i);
                num/=i;
            }
            string str2 = str;
            reverse(str2.begin(), str2.end());
            if(str!=str2) {
                return false;
            }
        }
        return true;
    }
};