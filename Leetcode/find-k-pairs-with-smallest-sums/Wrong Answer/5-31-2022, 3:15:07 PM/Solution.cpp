// https://leetcode.com/problems/find-k-pairs-with-smallest-sums

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        int n1 = nums1.size();
        int n2 = nums2.size();
        map<pair<int,int>, int> hash;
        
        pq.push({nums1[0]+nums2[0], {0, 0}});
        vector<vector<int>> ans;
        for(int i=0;i<k;i++) {
            auto top = pq.top();
            pq.pop();
            int idx1 = top.second.first, idx2 = top.second.second;
            ans.push_back({nums1[idx1], nums2[idx2]});
            
            if(idx1<n1-1 and hash.count({idx1+1, idx2}) == 0) {
                pq.push({nums1[idx1+1]+nums2[idx2], {idx1+1, idx2}});
                hash[{idx1+1, idx2}] = 1;
            }
            if(idx2<n2-1 and hash.count({idx1, idx2+1}) == 0) {
                pq.push({nums1[idx1]+nums2[idx2+1], {idx1, idx2+1}});
                hash[{idx1, idx2+1}] = 1;
            }
        }
        return ans;
        
    }
};