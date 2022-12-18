// https://leetcode.com/problems/split-array-into-fibonacci-sequence

class Solution {
private:
    vector<int> res;
    void util(string &num, int idx, vector<int> &ans) {
        int n = num.size();
        if(idx>=n and ans.size()>2) {
            res = ans;
            return;
        }
        
        long long val = 0;
        for(int i=idx;i<n;i++) {
            
            val = (val*10 + (num[i]-'0'));
            if(val>=INT_MAX) 
                break;
            
            if(ans.size()<=1){
                ans.push_back(val);
                util(num, i+1, ans);
                ans.pop_back();
            } else {
                int sz = ans.size();
                if(ans[sz-1] == val - ans[sz-2] ) {
                    ans.push_back(val);
                    util(num, i+1, ans);
                    ans.pop_back();
                }
            }
            if(val==0)
                break;   
        }
        
    }
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        util(num, 0, ans);
        return res;
    }
};