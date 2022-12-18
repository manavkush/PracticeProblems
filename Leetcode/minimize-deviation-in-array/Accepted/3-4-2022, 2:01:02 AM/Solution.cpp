// https://leetcode.com/problems/minimize-deviation-in-array

class Solution {
public:
    int minimumDeviation(vector<int>& a) {
        int n = a.size();
        set<int> s;
        for(int i=0;i<n;i++) {
            while(a[i]&1) {
                a[i]*=2;
            }
            s.insert(a[i]);
        }
        int low = (*(s.rbegin()) - *s.begin());
        while( (*s.rbegin())%2 ==0 ) {
            s.insert(*s.rbegin()/2);
            s.erase(--s.end());
            low = min(low, *s.rbegin() - *s.begin());
        }
        return low;
    }
};