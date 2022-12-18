// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        unordered_map<long long, vector<int>> hash;
        for(int i=0;i<n;i++) {
            hash[a[i]].push_back(i);
        }
        set<vector<int>> st;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(j==i)    continue;
                for(int k=0;k<n;k++) {
                    if(k==j || k==i) continue;
                    
                    // long long sum = a[i]+a[j]+a[k];
                    // long long req = target-sum;
                    long long req = (long long)target-(long long)a[i]-(long long)a[j]-(long long)a[k];
                    int cnt = 0;
                    if(hash.count(req)) {
                        for(auto x: hash[req]) {
                            vector<int> curr = {a[i], a[j], a[k]};
                            if(x==i||x==j||x==k) {
                                continue;
                            }
                            curr.push_back(a[x]);
                            sort(curr.begin(), curr.end());
                            st.insert(curr);
                        }
                    }
                    
                }
            }
        }
        vector<vector<int>> ans;
        for(auto itr=st.begin(); itr!=st.end();itr++) {
            ans.push_back(*itr);
        }
        return ans;
    }
};