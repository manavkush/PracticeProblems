// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusts(n+1);
        vector<int> trusted(n+1);
        for(int i=0;i<trust.size();i++) {
            trusts[trust[i][0]]++;
            trusted[trust[i][1]]++;
        }
        int count = 0;
        int index = 0;
        for(int i=1;i<=n;i++) {
            if(trusts[i]==0 and trusted[i]==n-1) {
                index = i;
                count++;
            }
        }
        if(count==1) return index;
        else return -1;
    }
};