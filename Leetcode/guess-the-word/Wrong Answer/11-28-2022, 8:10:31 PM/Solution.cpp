// https://leetcode.com/problems/guess-the-word

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
// #include <cstdlib>
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int curr = 0;
        vector<string> st;
        for(auto &x: words) {
            st.push_back(x);
        }

        for(int j=0, score=0;j<30 && score!=6;j++) {
            string word = st[0];
            score = master.guess(word);

            vector<string> newst;

            for(int itr=0;itr<st.size();itr++) {
                string newword = st[itr];
                
                int cnt_same_letters = 0;
                for(int i=0;i<6;i++) {
                    if(newword[i]==word[i])
                        cnt_same_letters++;
                }
                if(cnt_same_letters==score) {
                    newst.push_back(newword);
                }

            }
            st = newst;
        }
    }
};