// https://leetcode.com/problems/furthest-building-you-can-reach

class Solution {
// private:
//     int util(map<vector<int>, int> &hash, vector<int> &heights, int bricks, int ladders, int idx) {
//         int n = heights.size();
//         if(idx==n-1)
//             return n-1;
//         if(hash.find({idx, bricks, ladders})!=hash.end()) {
//             return hash[{idx, bricks, ladders}];
//         }
//         if(heights[idx]>=heights[idx+1])
//             return hash[{idx, bricks, ladders}] = util(hash, heights, bricks, ladders, idx+1);
//         int ans = idx;
//         int diff = heights[idx+1]-heights[idx];
//         if(bricks>=diff) {
//             ans = max(ans,util(hash, heights, bricks-diff, ladders, idx+1));
//         } 
//         if(ladders>0) {
//             ans = max(ans, util(hash, heights, bricks, ladders-1, idx+1));
//         }
//         return hash[{idx, bricks, ladders}] = ans;
//     }
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        set<int> st;
        int bricks_needed = 0;
        int i = 1;
        for(i=1;i<heights.size();i++) {
            int diff = heights[i] - heights[i-1];
            
            if(diff>0) {   // When help needed
                if(st.size()<ladders)
                    st.insert(diff);
                else {
                    int pos = distance(st.lower_bound(diff),st.end());
                    // - st.lower_bound(diff);
                    if(pos>=ladders) {
                        bricks_needed += diff;
                    } else {
                        set<int>::iterator itr = st.begin();
                        advance(itr,st.size()-ladders);
                        bricks_needed += *itr;
                    }
                    
                    if(bricks_needed>bricks) {
                        break;
                    } else {
                        st.insert(diff);    
                    }
                }
            }
        }
        return i-1;
    }
};