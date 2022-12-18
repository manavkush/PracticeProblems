// https://leetcode.com/problems/simplify-path

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int n = path.length();
        for(int i=0;i<n;i++) {
            if(path[i]=='/') {
                string temp;
                int j = i+1;
                for(;j<n and path[j]!='/';j++) {
                    temp+=path[j];
                } 
                if(temp.length()==0)
                    continue;
                if(temp.length()==1 and temp[0]=='.')
                    continue;
                if(temp.length()==2 and temp[0]=='.' and temp[1]=='.') {
                    if(!st.empty()) {
                        st.pop();
                    }
                    continue;
                }
                
                st.push(temp);
                i = j-1;
            }
        }
        vector<string> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        
        string ans = "/";
        for(int i=0;i<res.size();i++) {
            if(i!=0)
                ans += '/';
            ans += res[i];
        }
        return ans;
    }
};