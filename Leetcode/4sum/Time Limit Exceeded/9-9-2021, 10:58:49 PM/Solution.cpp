// https://leetcode.com/problems/4sum

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int n = a.size();
        unordered_map<long long, int> hash;
        
        for(int i=0;i<n;i++) {
            hash[a[i]]++;
        }
        vector<vector<int>> st;
        
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {            
                for(int k=j+1;k<n;k++) {
                    
                    long long sum = (long long)a[i] + (long long)a[j] + (long long)a[k];
                    long long req = target-sum;
                    int cnt = 0;
                    if((long long)a[i]==req) cnt++;
                    if((long long)a[j]==req) cnt++;
                    if((long long)a[k]==req) cnt++;
                    if(hash[req]>cnt) {
                        vector<int> curr = {a[i], a[j], a[k], (int)req};
                        sort(curr.begin(), curr.end());
                        // if(st.find(curr)==st.end())
                            st.push_back(curr);
                    }
                    
                }
            }
        }
        sort(st.begin(), st.end());
        st.erase(unique(st.begin(), st.end()), st.end());
        return st;       
    }
};
