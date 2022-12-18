// https://leetcode.com/problems/count-and-say

class Solution {
public:
    string countAndSay(int n) {
        unordered_map<int,string> hs;
        string ans = "1";
        for(int i=2;i<=n;i++) {
            string temp;
            int cnt=1;
            for(int i=1;i<ans.size();i++) {
                if(ans[i]==ans[i-1])
                    cnt++;
                else {
                    temp += (to_string(cnt)+ans[i-1]);
                    cnt = 1;
                }
            }
            temp += (to_string(cnt)+ans[ans.size()-1]);
            ans = temp;
            
        }
        return ans;
        
    }
};