// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game

class Solution {
private:
    bool static comp(vector<int> &a, vector<int> &b) {
        if(a[0]==b[0]) {
            return a[1] > b[1];
        }
        return a[0]<b[0];
    }
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), comp);
        int n = properties.size();
        int high = 0, ans = 0;
        for(int i=n-1;i>=0;i--) {
            if(high>properties[i][1]) {
                ans++;
            } 
            high = max(high, properties[i][1]);
        }
        return ans;
    }
};