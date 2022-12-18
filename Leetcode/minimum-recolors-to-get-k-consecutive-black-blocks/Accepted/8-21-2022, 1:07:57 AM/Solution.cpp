// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int black = 0, white = 0;
        for(int i=0;i<k;i++) {
            if(blocks[i]=='B')
                black++;
        }
        int ans = black;
        for(int i=k;i<n;i++) {
            if(blocks[i]=='B') {
                black++;
            }
            if(blocks[i-k]=='B') {
                black--;
            }
            ans = max(ans, black);
        }
        
        return k-ans;
    }
};