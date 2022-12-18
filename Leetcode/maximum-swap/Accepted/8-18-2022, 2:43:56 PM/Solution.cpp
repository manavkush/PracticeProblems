// https://leetcode.com/problems/maximum-swap

class Solution {
public:
    int maximumSwap(int num) {
        if(num/10==0)
            return num;
        string num2 = to_string(num);
        priority_queue<pair<char,int>> pq;
        int n = num2.size();
        int ans = num;
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                swap(num2[i], num2[j]);
                ans = max(ans, stoi(num2));
                swap(num2[i], num2[j]);
            }
        }
        return ans;
    }
};