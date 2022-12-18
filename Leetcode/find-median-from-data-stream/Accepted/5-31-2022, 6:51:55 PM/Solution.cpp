// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
private:
    double median; // not initialized
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
    int parity;
public:
    MedianFinder() {
        median = 1e6; // not initialized
        parity = 0;
    }
    
    void addNum(int num) {
        parity ^= 1;
        if(median==1e6) {
            median = num;
            maxpq.push(num);
        } else {
            if(num <= median) {
                maxpq.push(num);
                if(parity) {
                    median = maxpq.top();
                } else {
                    int top = maxpq.top();
                    maxpq.pop();
                    minpq.push(top);
                    int top2 = maxpq.top();
                    median = (top + top2)/2.0;
                }
            } else {
                minpq.push(num);
                if(parity) {
                    median = minpq.top();
                    maxpq.push(median);
                    minpq.pop();
                } else {
                    median = (minpq.top() + maxpq.top())/2.0;
                }
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */