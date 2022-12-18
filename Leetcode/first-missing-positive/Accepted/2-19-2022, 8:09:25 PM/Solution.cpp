// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            if(a[i]<0) {
                a[i] = 0;
            }
        }
        
        for(int i=0;i<n;) {
            if(a[i]<0) {
                i++;
                continue;
            }
            if(a[i]==0 || a[i]>n) {
                a[i] = -1;
                i++;
                continue;
            } 
            // now a[i] is positive
            int num = a[i]-1;
            if(a[num]<=-1) {
                a[num] = -2;
                a[i] = -1;
                i++;
                continue;
            } else {
                swap(a[num], a[i]);
                a[num] = -2;
    
            }
        }
        for(int i=0;i<n;i++) {
            if(a[i]==-1) {
                return i+1;
            }
        }
        return n+1;
    }
    
};