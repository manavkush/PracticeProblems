// https://leetcode.com/problems/reordered-power-of-2

class Solution {
private:
    bool util(vector<int> &digs, int curr, int total) {
        if(total == 0) {
            return (curr&(curr-1))==0;
        }
        for(int i=0;i<10;i++) {
            if(i==0 and curr==0) 
                continue;
            if(digs[i]) {
                digs[i]--;
                if(util(digs, curr*10+i, total-1))
                    return 1;
                digs[i]++;
            }
        }
        return false;
    }
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        for(int i=0;i<=29;i++) {
            string temp = to_string(1<<i);
            if(temp==s)
                return true;
        }
        return false;
    }
};