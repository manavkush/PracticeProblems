// https://leetcode.com/problems/stamping-the-sequence

class Solution {
private:
    
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = stamp.length();
        int m = target.length();
        vector<int> curr;
        int total_turns = 0, curr_turns = -1;
        
        while(curr_turns) {
            curr_turns = 0;
            for(int sz = n; sz>0;sz--) {
                for(int i=0;i<=n-sz;i++) {
                    string pattern = string(i, '*') + stamp.substr(i, sz) + string(n-sz-i, '*');
                    auto pos = target.find(pattern);
                    while(pos!=string::npos) {
                        curr_turns += sz;
                        curr.push_back(pos);
                        fill(target.begin()+pos, target.begin()+pos+n, '*');
                        pos = target.find(pattern);
                    }
                }
            }
            total_turns += curr_turns;
        }
        reverse(curr.begin(), curr.end());
        if(total_turns!=m) {
            curr = vector<int> ();
        }
        return curr;
    }
};