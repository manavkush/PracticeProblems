// https://leetcode.com/problems/repeated-string-match

class Solution {
private:
    void lps_(vector<int> &lps, string &b) {
        int i=0, j=1;
        int m = b.size();
        
        while(j<m) {
            if(b[i]==b[j]) {
                lps[j] = i+1;
                i++,j++;
            } else {
                if(i==0) {
                    j++;
                } else {
                    i = lps[i-1];
                }
            }
        }
    }
public:
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        
        
        // Generating LPS for string B('needle')
        vector<int> lps(m);
        lps_(lps, b);
        
        // for(auto &x: lps) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        
        // Modified KMP
        int i = 0, j = 0;
        
        while(i<n) {
            // Search completed
            if(j==m) {
                // cout<<i<<" "<<j<<endl;
                return (i+j-1)/n + 1;
            }
            if(a[(i+j)%n]==b[j]) {
                j++;
            } else {
                if(j>0) {
                    j=lps[j-1];
                }
                i++;
            }
        }
        return -1;
    }
};