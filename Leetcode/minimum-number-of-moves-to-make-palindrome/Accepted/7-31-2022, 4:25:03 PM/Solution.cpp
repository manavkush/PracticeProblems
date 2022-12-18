// https://leetcode.com/problems/minimum-number-of-moves-to-make-palindrome

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int ans = 0;
        while(s.length()) {
            auto pos = s.find(s.back());
            if(pos==s.length()-1) {
                ans += pos/2;
            } else {
                ans += pos;
                s.erase(pos, 1);
            }
            s.pop_back();
        }
        return ans;
    }
};