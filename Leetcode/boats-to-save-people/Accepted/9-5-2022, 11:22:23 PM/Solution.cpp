// https://leetcode.com/problems/boats-to-save-people

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        sort(people.begin(), people.end(), greater<int>());
        int l = 0 , r = n-1;
        int cnt = 0;
        while(l<=r) {
            if(people[l] + people[r] <= limit) {
                l++, r--;
            } else {
                l++;
            }
            cnt++;
        }
        return cnt;
    }
};