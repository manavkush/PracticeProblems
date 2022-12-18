// https://leetcode.com/problems/poor-pigs

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int oneTest = minutesToTest/minutesToDie;
        int pigs = 0;
        while(pow(oneTest+1, pigs) < buckets) {
            pigs++;
        }
        return pigs;
    }
};