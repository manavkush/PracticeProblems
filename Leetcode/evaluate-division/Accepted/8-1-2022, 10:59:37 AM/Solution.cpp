// https://leetcode.com/problems/evaluate-division

class Solution {
private:
    double dfs(vector<vector<pair<int,double>>> &adj, int a, int b, int par, double curr) {
        if(a==b) {
            return curr;
        }
        for(auto &x: adj[a]) {
            if(x.first!=par) {
                double ret = dfs(adj, x.first, b, a, curr*x.second);
                if(ret !=-1.0) {
                    return ret;
                }
            }
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, int> hash;
        int n = equations.size();
        vector<vector<pair<int,double>>> adj(2*n);
        for(int i=0;i<n;i++) {
            string s1 = equations[i][0], s2 = equations[i][1];
            int a,b;
            if(hash.find(s1)==hash.end()) {
                hash[s1] = hash.size();
            }
            if(hash.find(s2)==hash.end()) {
                hash[s2] = hash.size();
            }
            a = hash[s1];
            b = hash[s2];
            adj[b].push_back({a, values[i]});
            adj[a].push_back({b, 1.0/values[i]});
            // cout<<1.0/values[i]<<" ";
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++) {
            string s1 = queries[i][0], s2 = queries[i][1];
            
            int a,b;
            if(hash.find(s1)==hash.end() || hash.find(s2)==hash.end()) {
                ans.push_back(-1.0);
                continue;
            }
            if(s1==s2) {
                ans.push_back(1.0);
                continue;
            }
            a = hash[s1]; b = hash[s2];
            double curr = 1.0;
            ans.push_back(dfs(adj, b, a, b, curr));
        }
        return ans;
    }
};