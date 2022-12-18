// https://leetcode.com/problems/number-of-common-factors

class Solution {
public:
    int commonFactors(int a, int b) {
        if(a<b) {
            swap(a,b);
        }
        while(a%b!=0) {
            int temp = a%b;
            a = b;
            b = temp;
        }
        // gcd = b
        int count = 0;
        for(int i=1;i<=sqrt(b);i++) {
            if(b%i==0) {
                count++;
                int other = b/i;
                if(i!=other)
                    count++;
            }
        }
        return count;
    }
};