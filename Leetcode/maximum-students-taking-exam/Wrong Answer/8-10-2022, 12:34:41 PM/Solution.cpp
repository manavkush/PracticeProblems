// https://leetcode.com/problems/maximum-students-taking-exam

class Solution {
private:
    int ans = 0;
    void util(vector<vector<char>>& seats, int i, int j, int m, int n, int cnt) {
        if(i==m) {
            ans = max(ans, cnt);
            return;
        }
        bool aval = 1;
        if(j==n) {
            util(seats, i+1, 0, m, n, cnt);
            return;
        } 
        if(seats[i][j]=='#') {
            aval = 0;
        } 
        // // top left
        if(i>0 and j>0) {
            if(seats[i-1][j-1]=='1') {
                aval = 0;
            }
        }
        // // left
        if(j>0) {
            if(seats[i][j-1]=='1') {
                aval = 0;
            }
        }
        // top right
        if(j<n-1 and i>0) {
            if(seats[i-1][j+1]=='1') {
                aval = 0;
            }
        }
        if(aval) {
            seats[i][j] = '1';
            cnt++;
            util(seats, i, j+1, m, n, cnt);
            cnt--;
            seats[i][j] = '.';
        } else {
            util(seats, i, j+1, m, n, cnt);
        }
    }
public:
    int maxStudents(vector<vector<char>>& seats) {
        int cnt = 0;
        int m = seats.size(), n = seats[0].size();
        util(seats, 0, 0, m, n, cnt);
        return ans;
    }
};