// https://leetcode.com/problems/compare-version-numbers

class Solution {
private:
    vector<string> util(string &a) {
        int n = a.length();
        vector<string> ret;
        string temp;
        
        for(int i=0;i<n;) {
            if(a[i]=='.') {
                ret.push_back(temp==""? "0" : temp);
                temp = "";
                i++;
                while(i<n and a[i]=='0') {
                    i++;
                }
            } else {
                temp += a[i];
                i++;
            }
        }
        ret.push_back(temp == ""? "0" : temp);
        return ret;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1,v2;
        int n = version1.length();
        int m = version2.length();
        string temp;
        
        v1 = util(version1);
        v2 = util(version2);
        
        while(v1.size()<v2.size()) {
            v1.push_back("0");
        }
        while(v2.size()<v1.size()) {
            v2.push_back("0");
        }
        
        for(int i=0;i<v1.size();i++) {
            if(v1[i]<v2[i]) {
                return -1;
            } else if(v1[i]>v2[i]) {
                return 1;
            }
        }
        return 0;
    }
};