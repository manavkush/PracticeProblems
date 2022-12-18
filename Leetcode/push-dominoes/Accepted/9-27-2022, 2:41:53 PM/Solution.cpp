// https://leetcode.com/problems/push-dominoes

class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int> rights(n, INT_MAX);
        vector<int> lefts(n, INT_MAX);
        
        for(int i=0;i<n;i++) {
            if(dominoes[i]=='.')
                continue;
            
            if(dominoes[i]=='R') {
                rights[i] = 1;
                for(int j=i+1; j<n and dominoes[j]=='.'; j++) {
                    rights[j] = j-i+1;
                }
            } else {
                lefts[i] = 1;
                for(int j=i-1; j>=0 and dominoes[j]=='.'; j--) {
                    lefts[j] = i-j+1;
                }
            }
        }
        // for(auto &x: rights) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        // for(auto &x: lefts) {
        //     cout<<x<<" ";
        // }
        // cout<<endl;
        string temp = dominoes;
        for(int i=0;i<n;i++) {
            if(lefts[i]<rights[i]) {
                temp[i] = 'L';
            } else if(lefts[i]>rights[i]) {
                temp[i] = 'R';
            } else {
                temp[i] = '.';
            }
        }
        return temp;
    }
};