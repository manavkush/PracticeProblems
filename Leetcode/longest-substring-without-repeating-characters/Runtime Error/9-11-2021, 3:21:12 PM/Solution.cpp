// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> last_idx(26, -1);
        // unordered_map<int,int> last_idx;          // Stores the last index for each freq;
        
        int ans = 0;
        // vector<int> curr(26, 0);    // Stores the current freq;
        int curr_ans = 0;
        for(int i=0;i<26;i++) last_idx[i] = -1;
        
        for(int i=0;i<n;i++) {
            int idx = s[i]-'a';
            if(last_idx[idx]==-1) {
                last_idx[idx] = i;
                curr_ans++;
            } else {
                int ii = last_idx[idx];
                
                curr_ans = i-ii;
                for(int j=0;j<26;j++) last_idx[j] = -1;
                
                for(int j=ii+1;j<=i;j++) {
                    last_idx[s[j]-'a'] = j;
                }
                for(int j=0;j<26;j++) {
                    if(last_idx[j]!=-1) cout<<j<<","<<last_idx[j]<<" ";
                }
            }
            cout<<curr_ans<<"  ";
            ans = max(ans, curr_ans);
        }
        return ans;
    }
};