// https://leetcode.com/problems/permutation-sequence

class Solution {
private:
    void util(map<char,int> &st, int tot, int n, int k, string &ans) {
        if(n==1) {
            ans = ans + (st.begin()->first);
            return;
        } else {
            int grp_sz = tot/n;
            int grp = k/grp_sz;
            
            auto itr = st.begin();
            for(int i=0;i<grp;i++) {
                itr++;
            }
            ans += (itr->first);
            st.erase(itr);
            util(st, grp_sz, n-1, k%grp_sz, ans);
        }
    }
public:
    string getPermutation(int n, int k) {
        int tot = 1;
        for(int i=1;i<=n;i++) {
            tot*=i;
        }
        map<char,int> st;
        k--;
        for(int i=1;i<=n;i++) {
            st[('0'+ i)]++;
        }
        string ans;
        util(st,tot, n, k, ans);
        return ans;
    }
};