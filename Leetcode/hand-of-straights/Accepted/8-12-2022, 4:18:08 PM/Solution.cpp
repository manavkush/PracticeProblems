// https://leetcode.com/problems/hand-of-straights

class Solution {
public:
    bool isNStraightHand(vector<int>& a, int k) {
        int n = a.size();
        if(k==1)
            return 1;
        if(a.size()%k!=0)
            return 0;
        
        map<int,int> hash;
        for(auto &x: a) {
            hash[x]++;
        }
        vector<int> result;
        // auto itr = hash.begin();
        for(int cnt = 0; cnt<(n/k);cnt++) {
            auto it = hash.begin();
            while(it!=hash.end() and it->second==0)
                it++;
            it->second--;
            it++;
            for(int i=1;i<k;i++) {
                if(it==hash.end() || it->second==0)
                    return false;
                if(it->first - (prev(it)->first) != 1)
                    return false;
                it->second--;
                it++;
            }
        }
        return 1;
        
    }
};