// https://leetcode.com/problems/guess-the-word

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& words, Master& master) {
        int curr = 0;
        set<string> st;
        for(auto &x: words) {
            st.insert(x);
        }

        while(st.size()) {
            string word = *st.begin();
            int score = master.guess(word);
            if(score==6)
                return;
            st.erase(st.begin());

            auto itr = st.begin();
            
            while(itr!=st.end()) {
                string newword = *itr;
                int cnt_same_letters = 0;
                for(int i=0;i<6;i++) {
                    if(newword[i]==word[i])
                        cnt_same_letters++;
                }
                if(cnt_same_letters!=score) {
                    itr = st.erase(itr);
                } else {
                    itr++;
                }
            }
        }
    }
};