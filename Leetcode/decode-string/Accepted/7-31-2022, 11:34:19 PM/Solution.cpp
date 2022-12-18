// https://leetcode.com/problems/decode-string

class Solution {
private:
    string util(string &s, int &i) {
        // cout<<i<<" ";
        string ans;
        int num = 0;
        for(; i<s.size() ;i++) {
            // cout<<i<<" "<<num<<endl;
            if(s[i]=='[') {
                string returned = util(s, ++i);
                while(num) {
                    ans += returned;
                    num--;
                }
                // for(;num>0;num--)
            } else if(s[i]==']') {
                return ans;
            } else if(s[i]>='0' and s[i]<='9') {
                num = num*10 + (s[i]-'0');
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return util(s, i);
    }
};