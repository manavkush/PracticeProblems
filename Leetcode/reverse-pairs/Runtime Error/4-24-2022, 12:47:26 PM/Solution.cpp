// https://leetcode.com/problems/reverse-pairs

class Solution {
private:
    int util(vector<int> &a, int i, int f) {
        if(i==f) {
            return 0;
        } else if(f-i==1) {
            int ans = 0;
            if(a[i]>2ll*a[f]) {
                ans = 1;
            }
            sort(a.begin()+i, a.begin()+f+1);
            return ans;
        } else {
            int mid = (f-i)/2+i;
            int ans = util(a, i, mid) + util(a, mid+1, f);
            
            int ii = i, jj = mid+1;
            vector<int> temp;
            
            // counting the reverse pairs
            while(ii<=mid) {
                while(jj<=f and (a[ii]>2*a[jj])) {
                    jj++;
                }
                ans += jj-mid-1;
                ii++;
            }
            
            ii=i; jj = mid+1;
            while(ii<=mid) {
                while(jj<=f and a[jj]<=a[ii]) {
                    temp.push_back(a[jj++]);
                }
                temp.push_back(a[ii++]);
            }
            while(jj<=f) {
                temp.push_back(a[jj++]);
            }
            // copying to the actual array
            for(int j=0;j<temp.size();j++) {
                a[i+j] = temp[j];
            }
            return ans;
        }
    }    
public:
    int reversePairs(vector<int>& nums) {
        return util(nums, 0, nums.size()-1);
    }
};