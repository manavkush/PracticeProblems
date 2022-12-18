// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        int n = a.size();
        map<long long, int> hash;
        
        for(int i=0;i<n;i++) {
            hash[a[i]]++;
        }
        set<vector<int>> st;
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {            
                for(int k=j+1;k<n;k++) {
                    
                    long long sum = (long long)a[i] + (long long)a[j] + (long long)a[k];
                    long long req = (long long)target-sum;
                    int cnt = 0;
                    if((long long)a[i]==req) cnt++;
                    if((long long)a[j]==req) cnt++;
                    if((long long)a[k]==req) cnt++;
                    if(hash[req]>cnt) {
                        vector<int> curr = {a[i], a[j], a[k], (int)req};
                        sort(curr.begin(), curr.end());
                        // if(st.find(curr)==st.end())
                            st.insert(curr);
                    }
                    
                }
            }
        }
        vector<vector<int>> ans;
        while(!st.empty()) {
            ans.push_back(*st.begin());
            st.erase(st.begin());
        }
//         for(auto itr=st.begin(); itr!=st.end();itr++) {
//             ans.push_back(*itr);
            
//         }
        return ans;        
    }
};
