// https://leetcode.com/problems/valid-parenthesis-string

class Solution {
public:
    bool checkValidString(string s) {
        int curr = 0;
        stack<char> st;
        int n = s.length();
        int leftmin = 0, leftmax = 0;
        for(int i=0;i<n;i++) {
            if(s[i]=='(') {
                leftmin++, leftmax++;
            } else if(s[i]==')') {
                leftmin = max(0, leftmin-1);
                leftmax--;
                if(leftmax<0)
                    return false;
            } else {
                leftmax++;
                leftmin = max(0, leftmin-1);
            }
        }
        if(leftmin==0)
            return true;
        return false;
    }
};