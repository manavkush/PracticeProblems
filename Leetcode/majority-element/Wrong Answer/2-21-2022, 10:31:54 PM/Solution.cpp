// https://leetcode.com/problems/majority-element

class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n = a.size();
        int x=-1,y=-1;
        int countx=0, county=0;
        for(int i=0;i<n;i++) {
            if(x==a[i]) {
                countx++;
            } else if(y==a[i]) {
                county++;
            } else if(x==-1) {
                x = a[i];
                countx++;
            } else if(y==-1) {
                y = a[i];
                county++;
            } else {
                countx--;
                county--;
                if(countx==0) {
                    x = -1;
                }
                if(county==0) {
                    y = -1;
                }
            }
            if(countx>n/2) {
                return x;
            } else if(county>n/2) {
                return y;
            }
        }
        return x;
    }
};