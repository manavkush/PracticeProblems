// https://leetcode.com/problems/utf-8-validation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool valid = 1;
        
        int n = data.size();
        
        for(int i=0;i<n;i++) {
            int x = data[i];
            if((x>>7 & 1)==0) {
                continue;
            }
            if((x>>6 & 1)==0) {
                valid = 0;
                break;
            }
            int len = 0;
            if((x>>5 & 1) == 0) {
                len = 2;
            } else if((x>>4 & 1) == 0) {
                len = 3;
            } else if((x>>3 & 1) == 0 ) {
                len = 4;
            } else {
                valid = 0;
                break;
            }
            if(i+len>n) {
                // cout<<"#";
                valid = 0;
                break;
            }
            for(int j=1;j<len;j++) {
                // cout<<"*";
                if((data[i+j]>>7 & 1) and ((data[i+j]>>6 & 1)==0)) {
                    continue;
                } else {
                    valid = false;
                    break;
                }
            }
            i+=len-1;
        }
        // cout<<endl;
        return valid;
    }
};