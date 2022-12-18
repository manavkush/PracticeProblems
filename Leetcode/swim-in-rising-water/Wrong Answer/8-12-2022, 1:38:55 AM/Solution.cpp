// https://leetcode.com/problems/swim-in-rising-water

class Solution {
private:
    vector<int> dr = {0, 0, 1, -1};
    vector<int> dc = {1, -1, 0, 0};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> distances(n, vector<int> (n, INT_MIN));
        set<pair<int,pair<int,int>>> st;
        
        distances[0][0] = grid[0][0];
        st.insert({grid[0][0], {0,0}});
        
        while(!st.empty()) {
            auto top = *st.begin();
            int curr = top.first;
            pair<int,int> pos = top.second;
            st.erase(st.begin());
            
            // distances[pos.first][pos.second] = curr;
            for(int i=0;i<4;i++) {
                int rr = pos.first+dr[i];
                int cc = pos.second+dc[i];
                if(rr<0||cc<0||rr>=n||cc>=n||distances[rr][cc]>=max(curr, grid[rr][cc])) 
                    continue;
                auto found = st.find({distances[rr][cc], {rr, cc}});
                if(found!=st.end()) 
                    st.erase(found);
                st.insert({max(curr, grid[rr][cc]), {rr, cc}});
                distances[rr][cc] = curr;
            }
        }
        return distances[n-1][n-1];
    }
};