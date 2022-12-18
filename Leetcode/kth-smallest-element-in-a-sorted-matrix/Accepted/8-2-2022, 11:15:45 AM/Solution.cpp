// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix

class Solution {
private:
    int util(vector<vector<int>>& matrix, int mid) {
        int n = matrix.size();
        int i = n-1, j = 0;
        int count = 0; // stores no of elements <= element
        while(i>=0 and j<n) {
            if(matrix[i][j]>mid) {
                i--;
            } else {
                j++;
                count += (i+1);
            }
        }
        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int i = matrix[0][0], j = matrix[n-1][n-1];
        while(i<j) {
            int mid = i + (j-i)/2;
            int pos = util(matrix, mid);
            if(pos<k) {
                i = mid+1;
            } else {
                j = mid;
            }
        }
        return i;
    }
};