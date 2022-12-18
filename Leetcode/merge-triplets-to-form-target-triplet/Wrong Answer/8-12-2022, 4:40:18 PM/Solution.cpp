// https://leetcode.com/problems/merge-triplets-to-form-target-triplet

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<vector<int>> newtrip;
        int a=0,b=0,c=0;
        for(auto &x: triplets) {
            if(x[0]>target[0])
                continue;
            if(x[1]>target[1])
                continue;
            if(x[2]>target[1])
                continue;
            newtrip.push_back(x);
            if(x==target) 
                return 1;
            a = max(a, x[0]);
            b = max(b, x[1]);
            c = max(c, x[2]);
        }
        if(a==target[0] and b==target[1] and c==target[2])
            return 1;
        return 0;
    }
};