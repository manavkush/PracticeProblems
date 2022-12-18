// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
private: 
    multiset<int> s1, s2;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        bool flag = 0;
        if(s1.empty()) {
            s1.insert(num);
        } else if(s2.empty()) {
            s2.insert(num);
        } else if(num<*s2.begin()) {
            s1.insert(num);
            if(s1.size()>s2.size()+1) {
                int el = *(--s1.end());
                s1.erase(--s1.end());
                s2.insert(el);
            } 
        } else {
            s2.insert(num);
            if(s2.size()>s1.size()+1) {
                int el = *(s2.begin());
                s2.erase(s2.begin());
                s1.insert(el);
            }
        }
    }
    
    double findMedian() {
        if(s1.size()==s2.size()) {
            return (*(--s1.end()) + (*s2.begin()))*1.0/2;
        } else if(s1.size()>s2.size()) {
            return *(--s1.end())*1.0;
        } else {
            return *(s2.begin())*1.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */