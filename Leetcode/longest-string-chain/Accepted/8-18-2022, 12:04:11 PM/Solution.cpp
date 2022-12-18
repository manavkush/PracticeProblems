// https://leetcode.com/problems/longest-string-chain

class Solution {
private:
    bool static comp(string &a, string &b) {
        return a.length()<b.length();
    }
    bool lcs(string &a, string &b) {
        int len1=a.length(), len2 = b.length();
        int i = 0, j=0;
        int cnt = 0;
        while(i<len1 and j<len2) {
            if(a[i]!=b[j]) {
                if(cnt)
                    return 0;
                cnt++;
                j--;
            }
            i++;
            j++;
        }
        return cnt<=1;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        int n = words.size();
        vector<int> dp(n, 1);
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                int len1=words[i].length(), len2 = words[j].length();
                if(len1==1+len2) {
                    if(lcs(words[i], words[j])) {
                        dp[i] = max(dp[i], dp[j]+1);
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};