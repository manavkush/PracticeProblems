// https://leetcode.com/problems/find-median-from-data-stream

class MedianFinder {
private:
    priority_queue<int> maxpq;
    priority_queue<int, vector<int>, greater<int>> minpq;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        minpq.push(num);
        maxpq.push(minpq.top());
        minpq.pop();
        // divided the numbers into 2 groups

        if(maxpq.size()-minpq.size()>1) {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
    }
    
    double findMedian() {
        if(maxpq.size()>minpq.size()) {
            return maxpq.top();
        } else {
            return (maxpq.top()+minpq.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */