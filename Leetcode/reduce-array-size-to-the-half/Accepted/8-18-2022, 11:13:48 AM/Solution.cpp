// https://leetcode.com/problems/reduce-array-size-to-the-half

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int,int> hs;
        vector<pair<int,int>> vec;
        for(auto &x: arr) {
            hs[x]++;
        }
        for(auto &x: hs) {
            vec.push_back({x.second, x.first});
        }
        sort(vec.begin(), vec.end(), greater<pair<int,int>>() );
        int sum = 0, i=0;
        for(i=0;i<vec.size();i++) {
            if(sum + vec[i].first>=(n+1)/2)
                break;
            sum += vec[i].first;
        }
        return i+1;
    }
};