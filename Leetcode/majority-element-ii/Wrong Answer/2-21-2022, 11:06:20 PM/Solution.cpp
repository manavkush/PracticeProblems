// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
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
            // if(countx>n/3) {
            //     return x;
            // } else if(county>n/3) {
            //     return y;
            // }
        }
        if(countx>0) {
            int sum = 0;
            for(int i=0;i<n;i++) {
                if(a[i]==x) {
                    sum++;
                }
            }
            if(sum>n/3) 
                ans.push_back(x);
        } 
        if(county>0) {
            int sum = 0;
            for(int i=0;i<n;i++) {
                if(a[i]==y) {
                    sum++;
                }
            }
            if(sum>n/3) 
                ans.push_back(y);
        } 
        return ans;
    }
};