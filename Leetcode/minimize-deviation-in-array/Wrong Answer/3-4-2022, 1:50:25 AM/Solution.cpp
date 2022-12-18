// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int n = a.size();
        set<int> s;
        for(int i=0;i<n;i++) {
            while(a[i]%2==0) {
                a[i]/=2;
            }
            s.insert(a[i]);
        }
        int low = (*(--s.end()) - *s.begin());
        while(1) {
            int curr = abs(*(--s.end()) - 2*(*s.begin()));
            if(curr < low) {
                s.insert(2*curr);
                s.erase(s.begin());
                low = curr;
            } else {
                break;
            }
        }
        return low;
    }
};