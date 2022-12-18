// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets

class Solution {
private:
    bool check(vector<int> &bloomDay, int m, int k, int high ) {
        int i = 0, n = bloomDay.size();
        int cnt = 0;
        while(i<n and cnt<m) {
            bool flag = 0;
            for(int j=0;j<k;j++) {
                if(i+j>=n || bloomDay[i+j]>high) {
                    flag = 1;
                    i=i+j+1;
                    break;
                }
            }
            if(!flag) {
                cnt++;
                i+=k;
            }
        }
        return cnt>=m;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(n/k<m) return -1;
        int l = 0, r = *max_element(bloomDay.begin(), bloomDay.end());
        
        while(l+1<r) {
            int mid = (l+r)/2;
            if(check(bloomDay, m, k, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};