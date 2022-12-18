// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
private:
    int numbersmaller(vector<vector<int>> &matrix, int el) {
        int n = matrix.size();
        int i=0, j = n-1;
        int cnt = 0;
        while(i<n and j>=0 ) {
            if(matrix[i][j]>el) {
                j--;
            } else {
                cnt+=j+1;
                i++;
            }
        }
        return cnt;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n-1][n-1];
        while(l<r) {
            int mid = (r-l)/2+l;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            int cnt = numbersmaller(matrix, mid);
            if(cnt<k-1) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return l;
    }
};