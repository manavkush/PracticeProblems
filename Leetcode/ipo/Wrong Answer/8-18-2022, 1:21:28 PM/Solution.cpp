// https://leetcode.com/problems/ipo

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        multiset<pair<int,int>> vec;
        int n = profits.size();
        for(int i=0;i<n;i++) {
            vec.insert({capital[i], profits[i]});
        }
        // sort(vec.begin(), vec.end());
        for(int i=0;i<k;i++) {
            auto pos = vec.upper_bound({w, INT_MAX});
            if(pos==vec.begin())
                break;
            w += prev(pos)->second;
            vec.erase(prev(pos));
        }
        return w;
    }
};