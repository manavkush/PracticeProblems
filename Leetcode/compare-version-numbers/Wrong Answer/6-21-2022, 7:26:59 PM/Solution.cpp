// https://leetcode.com/problems/compare-version-numbers

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<string> v1,v2;
        int n = version1.length();
        int m = version2.length();
        string temp;
        
        for(int i=0;i<n;) {
            if(version1[i]=='.') {
                v1.push_back((temp.empty() )? "0" : temp);
                // if(temp) {
                //     v1.push(temp);                    
                // } else {
                //     v1.push("0");
                // }
                temp = "";
                i++;
                while(i<n and version1[i]=='0') {
                    i++;
                }
            } else {
                temp += version1[i];
                i++;
            }
        }
        temp = "";
        for(int i=0;i<m;) {
            if(version2[i]=='.') {
                v2.push_back((temp.empty() )? "0" : temp);
                // if(temp) {
                //     v2.push(temp);
                // } else {
                //     v2.push("0");
                // }
                temp = "";
                i++;
                while(i<m and version2[i]=='0') {
                    i++;
                }
            } else {
                temp += version2[i];
                i++;
            }
        }
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