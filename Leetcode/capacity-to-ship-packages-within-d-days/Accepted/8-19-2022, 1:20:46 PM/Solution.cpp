// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
private:
    bool check(vector<int> &weights, int days, int cap) {
        int n = weights.size();
        if(*max_element(weights.begin(), weights.end()) > cap) {
            return false;
        }
        int curr = 0;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            if(curr+weights[i]<=cap) {
                curr+= weights[i];
            } else {
                cnt++;
                curr = weights[i];
            }
        }
        return cnt+1<=days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0, r = 25e6;
        while(l+1<r) {
            int mid = (l+r)/2;
            if(check(weights, days, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};