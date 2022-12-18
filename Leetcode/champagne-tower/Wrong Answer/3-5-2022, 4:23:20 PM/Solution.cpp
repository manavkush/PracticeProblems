// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        int i=1;
        vector<double> prev(query_row+1);
        for( i=0;i<=query_row;i++) {
            bool flag = 0;
            long long curr = 1;
            int already = (i*(i+1))/2;
            for(int j=0;j<=i;j++) {
                
                curr = (curr*(i-j+1))/(i+1);
                double ans = (max(poured - already, 0)*1.0)/(1.0*curr);
                if(ans>1)
                    flag = 1;
                if(i==query_row and j==query_glass) {
                    return ans;
                }
            }
            if(!flag) 
                break;
        }
        return 0.0;
    }
};