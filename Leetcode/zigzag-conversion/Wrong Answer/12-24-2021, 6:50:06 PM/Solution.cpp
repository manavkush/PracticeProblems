// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        // int m = (n/4)*4;
        string a,b,c;
        for(int i=0;i<n;i++) {
            int mod = i%4;
            if(mod==0) {
                a += s[i];
            } else if(mod==1 || mod==3) {
                b += s[i];
            } else {
                c += s[i];
            }
        }
        return a+b+c;
    }
};