// https://leetcode.com/problems/smallest-integer-divisible-by-k

class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0 || k%5==0) return -1;
        unordered_map<int,int> hit;
        int curr = 0;   // stores the num
        int ans = 0;    // stores the length
        for(int i=0;i<k;i++) {
            ans++;
            curr = (curr*10+1)%k;
            if(curr==0)   return ans;
            
            if(hit.find(curr)!=hit.end())   return -1;
            hit[curr]++;
        }
        return -1;
    }
};