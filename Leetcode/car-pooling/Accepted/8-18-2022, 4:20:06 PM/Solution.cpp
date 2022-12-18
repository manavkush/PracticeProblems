// https://leetcode.com/problems/car-pooling

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> curr(1005);
        for(auto &x: trips) {
            curr[x[1]]+=x[0];
            curr[x[2]]-=x[0];
        }
        for(int i=1;i<1005;i++) {
            curr[i] += curr[i-1];
        }
        return (*max_element(curr.begin(), curr.end()) <= capacity);
        
    }
};