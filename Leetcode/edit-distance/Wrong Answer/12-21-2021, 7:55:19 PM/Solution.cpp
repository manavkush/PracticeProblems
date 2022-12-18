// https://leetcode.com/problems/edit-distance

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        // if(n==0 || m==0)    return max(n,m);
        vector<int> prev(m+1),curr(m+1);
        
        for(int i=0;i<=m;i++) {
            prev[i] = i;
        }
        curr[0] = 1;
        for(int i=0;i<n;i++) {
            curr[0] = i+1;
            for(int j=0;j<m;j++) {
                if(word1[i]==word2[j]) {
                    curr[j+1] = prev[j];
                } else {
                    curr[j+1] = min({curr[j], prev[j], prev[j+1]})+1;
                }
            }
            // for(int i=0;i<=m;i++) {
            //     cout<<curr[i]<<" ";
            // }
            // cout<<endl;
            prev = curr;
        }
        
        return curr[m];
    }
};