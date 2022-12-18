// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        map<int,int> last_idx;          // Stores the last index for each freq;
        for(int i=0;i<26;i++) {
            last_idx[i] = -1;
        }
        // vector<vector<int>> hash(n);    // Stores the freq for each index
        int ans = 0;
        // vector<int> curr(26, 0);    // Stores the current freq;
        int curr_ans = 0;
        
        for(int i=0;i<n;i++) {
            int idx = s[i]-'a';
            
            if(last_idx.find(idx)==last_idx.end()) {
                curr_ans++;
                last_idx[idx] = i;             
            } else {
                curr_ans = i - last_idx[idx];
                last_idx.clear();
                for(int j=last_idx[idx]+1; j<=i ;j++) {
                    last_idx[s[j]-'a'] = j;         
                }
            }
            ans = max(ans, curr_ans);
        }
        return ans;
    }
};