// https://leetcode.com/problems/split-array-into-consecutive-subsequences

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /*
            The intiution of this is that an element can be added at the end of existing
            sequence. If it can't, then we'll have to make a new sequence starting from 
            that element. This newly formed sequence should be valid. Hence we also add the 
            next 2 consecutive element to the sequence. If at any point any element cannot 
            satisfy any of these 2 choices, return false;
        */
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