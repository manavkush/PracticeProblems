// https://leetcode.com/problems/binary-watch

class Solution {
public:
    vector <int> h = {1, 2, 4, 8};
    vector <int> m = {1, 2, 4, 8, 16, 32};
    vector <string> ans;
    void solve(int i, int j, int sum1, int sum2, int turnedOn, vector<string> &ans) {
        if(sum1 > 11 || sum2 > 59) 
            return;
        if(turnedOn == 0 ) {
            string curr;
            if(sum2>9) {
                curr = to_string(sum1)+":"+to_string(sum2);
            } else {
                curr = to_string(sum1)+":0"+to_string(sum2);
            }
            cout<<(curr)<<",";
            auto itr = lower_bound(ans.begin(), ans.end(), curr);
            if((itr == ans.end()) || (*itr!=curr))
            ans.push_back(curr);
            sort(ans.begin(), ans.end());
            return;
        }
        else if(i==4 && j==6) {
            return;
        }
        // cout<<i<<","<<j<<" ; ";
        if(i==4) {
            solve(i , j + 1, sum1, sum2 + m[j], turnedOn - 1, ans);
            solve(i , j + 1, sum1, sum2, turnedOn, ans);    
        } else if(j==6) {
            solve(i + 1, j, sum1 + h[i], sum2, turnedOn - 1, ans);
            solve(i + 1, j, sum1, sum2, turnedOn, ans);
        } else {
            solve(i + 1, j, sum1 + h[i], sum2, turnedOn - 1, ans);
            solve(i + 1, j, sum1, sum2, turnedOn, ans);
            solve(i , j + 1, sum1, sum2 + m[j], turnedOn - 1, ans);
            solve(i , j + 1, sum1, sum2, turnedOn, ans);
        }
        
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector <string> ans;
        solve(0, 0, 0 , 0, turnedOn, ans);
        return ans;
    }
};
