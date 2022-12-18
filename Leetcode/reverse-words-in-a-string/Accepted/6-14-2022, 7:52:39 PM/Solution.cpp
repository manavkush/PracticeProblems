// https://leetcode.com/problems/reverse-words-in-a-string

class Solution {
public:
    string reverseWords(string s) {
        
        int n = s.length();
        int i,f;
        string ans;
        
        for(int i=n-1;i>=0;i--) {
            if(s[i]==' ')
                continue;
            int j = i;
            
            for( j=i;j>=0;j--) {
                if(s[j]==' ')
                    break;
            }
            int len = i-j;
            if(ans.length())
                ans += ' ';
            
            ans += s.substr(j+1, len);
            i = j;
        }
        return ans;
    }
};