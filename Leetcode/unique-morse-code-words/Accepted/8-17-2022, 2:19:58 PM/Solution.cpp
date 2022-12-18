// https://leetcode.com/problems/unique-morse-code-words

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        int n = words.size();
        vector<string> hash {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0;i<n;i++) {
            string temp;
            for(int j=0;j<words[i].length();j++) {
                int ch = words[i][j]-'a';
                temp += hash[ch];
            }
            st.insert(temp);
        }
        return st.size();
    }
};