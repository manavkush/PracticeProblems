// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        vector<int> greater(nums2.size(), -1);
        unordered_map<int,int> hash;
        for(int i=0;i<nums2.size();i++) {
            hash[nums2[i]] = i;
            while((!st.empty()) and (nums2[st.top()]<nums2[i])) {
                int idx = st.top();
                greater[idx] = i;
                st.pop();
            }
            st.push(i);
        }
        vector<int> ans;
        // for(auto &x: greater) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<nums1.size();i++) {
            int id = greater[hash[nums1[i]]];
            ans.push_back(id==-1 ? -1 : nums2[id]);
        }
        return ans;
    }
};