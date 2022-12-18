// https://leetcode.com/problems/maximum-total-beauty-of-the-gardens

class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        int n = flowers.size();
        sort(flowers.begin(), flowers.end());
        
        long long done = 0;
        
        while(!flowers.empty() and flowers.back()>=target) {
            flowers.pop_back();
            done++;
        }
        
        int m = flowers.size();
        if(m==0) return full*done;
        
        vector<long long> fill(m);
        for(int i=1;i<m;i++) {
            fill[i] = fill[i-1] + i*(flowers[i]-flowers[i-1]);
        }
        
        for(auto &x: fill) cout<<x<<" ";
        cout<<endl;
        
        long long ans = 0;
        auto pos = prev(upper_bound(fill.begin(), fill.end(), newFlowers));
        
        long long left = newFlowers - *(pos);
        int idx = (pos) - fill.begin();
        long long high = min((long long)(target-1), (left)/m + flowers[idx]);
        ans = max(ans, high*(long long)partial + done*(long long)full);
        
        long long target_filled = 0;
        
        for(long long i=m-1;i>=1;i--) {
            cout<<ans<<" ";
            long long need = target-flowers[i];
            if(target_filled + need > newFlowers)
                break;
            done++;
            target_filled += need;
            
            auto pos = prev(upper_bound(fill.begin(), fill.begin()+i, newFlowers-target_filled));
            long long left = (newFlowers - target_filled) - (*pos);
            int idx = (pos) - fill.begin();
            high = min((long long)(target-1), (left)/i + flowers[idx]);
            ans = max(ans, high*(long long)partial + (long long)full*done);
        }
        cout<<ans<<" ";
        if(target_filled + target-flowers[0] <= newFlowers) {
            done++;
            ans = max(ans, done*full);
        }
        
        return ans;
    }
};