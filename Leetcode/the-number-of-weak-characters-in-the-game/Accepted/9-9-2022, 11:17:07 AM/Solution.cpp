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
        for(auto &x: properties) {
            cout<<x[0]<<","<<x[1]<<" ";
        }
        cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++) {
            vector<int> curr = {copy[i][0], INT_MAX};
            auto pos = upper_bound(properties.begin(), properties.end(), curr);
            
            if(pos == properties.end()) 
                continue;
            // cout<<copy[i][0]<<"#"<<copy[i][1]<<"|";
            // cout<<(*pos)[0]<<","<<(*pos)[1]<<" ";
            
            if((*pos)[1] > copy[i][1] and (*pos)[0] > copy[i][0]) {
                ans++;
            }
        }
        // cout<<endl<<endl;
        return ans;
    }
};