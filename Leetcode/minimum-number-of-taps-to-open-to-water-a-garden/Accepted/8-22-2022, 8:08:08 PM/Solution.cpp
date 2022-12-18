// https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden

class Solution {
private:
    bool static comp(pair<int,int> &a, pair<int,int> &b) {
        if(a.first!=b.first) {
            return a.first<b.first;
        } else {
            return a.second > b.second;
        }
    }
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> a;
        for(int i=0;i<=n;i++) {
            a.push_back({i-ranges[i], i+ranges[i]});
        }
        sort(a.begin(), a.end(), comp);
        int cnt = 0;
        int idx = 0;
        int high = 0;
        while(idx<n and high<n) {
            int curr = high;
            while(idx<n and a[idx].first <=high) {
                curr = max(a[idx].second, curr);
                idx++;
            }
            if(high == curr) {
                return -1;
            }
            high = max(high, curr);
            cnt++;
        }
        return cnt;
    }
};