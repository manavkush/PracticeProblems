// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int n = a.size();
        set<vector<int>> hash;
        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++) {
            if(i>0 and a[i]==a[i-1])
                continue;
            int j = i+1;
            int k = n-1;
            while(j<k) {
                int sum = a[i]+a[j]+a[k];
                if(sum==0) {
                    vector<int> temp = {a[i],a[j],a[k]};
                    ans.push_back(temp);
                    while(j<k and a[j]==a[j+1]) j++;
                    while(k>j and a[k]==a[k-1]) k--;
                    j++;
                    k--;
                } else if(sum<0) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return ans;
    }
};