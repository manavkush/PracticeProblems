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

        while(st.size()) {
            int word_no = rand()%st.size();
            string word = st[word_no];
            int score = master.guess(word);
            if(score==6)
                return;
            
            st[word_no] = "*";

            vector<string> newst;

            for(int itr=0;itr<st.size();itr++) {
                string newword = st[itr];
                if(newword=="*")
                    continue;
                
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