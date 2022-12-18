// https://leetcode.com/problems/majority-element-ii

class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        int n = a.size();
        vector<int> ans;
        int x=INT_MIN,y=INT_MIN;
        int countx=0, county=0;
        for(int i=0;i<n;i++) {
            if(x==a[i]) {
                countx++;
            } else if(y==a[i]) {
                county++;
            } else if(x==INT_MIN) {
                x = a[i];
                countx++;
            } else if(y==INT_MIN) {
                y = a[i];
                county++;
            } else {
                countx--;
                county--;
                if(countx==0) {
                    x = INT_MIN;
                }
                if(county==0) {
                    y = INT_MIN;
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