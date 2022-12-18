// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        unordered_map<long long, int> hash;
        for(int i=0;i<n;i++) {
            hash[a[i]]++;
        }
        set<vector<int>> st;
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(j==i)    continue;
                for(int k=0;k<n;k++) {
                    if(k==j || k==i) continue;
                    
                    long long sum = (long long)a[i] + (long long)a[j] + (long long)a[k];
                    long long req = (long long)target-sum;
                    int cnt = 0;
                    if(a[i]==req) cnt++;
                    if(a[j]==req) cnt++;
                    if(a[k]==req) cnt++;
                    if(hash[req]>cnt) {
                        vector<int> curr = {a[i], a[j], a[k], (int)req};
                        sort(curr.begin(), curr.end());
                        if(st.find(curr)==st.end())
                            st.insert(curr);
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
