// https://leetcode.com/problems/maximum-split-of-positive-even-integers

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum&1) {
            return ans;
        }
        long long curr = 0;
        for(int i=2;i<=finalSum;i+=2) {
            if(curr+i<=finalSum) {
                curr += i;
                ans.push_back(i);
            } else {
                long long last = ans.back();
                last += (finalSum-curr);
                ans.pop_back();
                ans.push_back(last);
                break;
            }
        }
        return ans;
    }
};