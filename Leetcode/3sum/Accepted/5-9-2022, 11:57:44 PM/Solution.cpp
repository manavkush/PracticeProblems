// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        set<vector<int>> hash;
        for(int i=0;i<n-2;i++) {
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = a[i]+a[j]+a[k];
                if(sum==0) {
                    vector<int> temp = {a[i],a[j],a[k]};
                    hash.insert(temp);
                    j++;
                    k--;
                } else if(sum<0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto x: hash) {
            ans.push_back(x);
        }
        return ans;
    }
};