// https://leetcode.com/problems/cinema-seat-allocation

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> grid(n+1, vector<int> (10+1));
        for(auto &x: reservedSeats) {
            int r = x[0];
            int c = x[1];
            r--, c--;
            mp[r].push_back(c);
        }
        int ans = n*2;
        for(auto &x: mp) {
            sort(x.second.begin(), x.second.end());
            vector<int> seats(10, 0);
            for(auto &y: x.second) {
                seats[y]++;
            }
            for(int i=1;i<10;i++) {
                seats[i]+=seats[i-1];
            }
            int placed = 0;
            
            if(seats[8]==seats[0]) {
                placed=2;
            } else {
                if((seats[0]==seats[4]) || (seats[2]==seats[6]) || (seats[4]==seats[8])) {
                    placed++;
                }
            }
            ans -= (2-placed);
        }
        return ans;
    }
};