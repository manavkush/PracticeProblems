class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if(numRows==1)    return s;
        // int m = (n/4)*4;
        string vec[numRows];
        int m = 2*numRows-2;
        for(int i=0;i<n;i++) {
            int mod = i%m;
            
            if(mod>=numRows) {
                mod = 2*numRows-mod-2;
            }
            vec[mod] += s[i];
        }
        string ans;
        for(int i=0;i<numRows;i++) {
            ans+=vec[i];
        }
        return ans;
    }
};