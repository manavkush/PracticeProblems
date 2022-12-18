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
            int ans1 = util(a, i, mid);
            int ans2 = util(a, mid+1, f);
            int ans3 = 0;
            int ii = i, jj = mid+1;
            vector<int> temp;
            while(ii<=mid && jj<=f) {
                if(a[ii]<=a[jj]) {
                    temp.push_back(a[ii++]);
                } else {
                    temp.push_back(a[jj]);
                    for(int v=ii;v<=mid;v++) {
                        if(a[v]>2ll*a[jj]) {
                            ans3+= (mid-v+1);
                            break;
                        }
                    }
                    // ans3 += (a.begin()+mid+1) - upper_bound(a.begin()+i, a.begin()+mid+1, 2ll*a[jj]);
                    jj++;
                }
            }
            while(ii<=mid) {
                temp.push_back(a[ii++]);
            }
            while(jj<=f) {
                temp.push_back(a[jj++]);
            }
            for(int j=0;j<temp.size();j++) {
                a[i+j] = temp[j];
            }
            return ans1+ans2+ans3;
        }
    }    
public:
    int reversePairs(vector<int>& nums) {
        return util(nums, 0, nums.size()-1);
    }
};