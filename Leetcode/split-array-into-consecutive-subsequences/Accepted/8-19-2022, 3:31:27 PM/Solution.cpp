// https://leetcode.com/problems/split-array-into-consecutive-subsequences

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> left, end;
        for(auto &x: nums) {
            left[x]++;
        }
        for(auto &x: nums) {
            if(left[x]==0)
                continue;
            left[x]--;
            if(end[x-1]>0) {
                end[x]++;
                end[x-1]--;
            } else if(left[x+1] and left[x+2]) {
                left[x+1]--;
                left[x+2]--;
                end[x+2]++;
            } else {
                return false;
            }
        }
        return true;
    }
};