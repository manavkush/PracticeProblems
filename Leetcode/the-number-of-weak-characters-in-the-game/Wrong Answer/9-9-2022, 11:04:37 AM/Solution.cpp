// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        vector<vector<int>> copy = properties;
        sort(properties.begin(), properties.end());
        int n = properties.size();
        int high = 0;
        for(int i=n-1;i>=0;i--) {
            high = max(high, properties[i][1]);
            properties[i][1] = high;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            auto pos = upper_bound(properties.begin(), properties.end(), copy[i]);
            if( pos == properties.end()) 
                continue;
            if((*pos)[1] > copy[i][1])
                ans++;
        }
        return ans;
    }
};