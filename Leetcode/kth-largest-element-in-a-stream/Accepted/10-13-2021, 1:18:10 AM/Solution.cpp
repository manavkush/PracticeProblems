// https://leetcode.com/problems/kth-largest-element-in-a-stream

class KthLargest {
private: 
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0;i<nums.size();i++) {
            if(pq.size()<k) {
                pq.push(nums[i]);
            } else if(nums[i]>pq.top()) {
                    pq.push(nums[i]);
                    pq.pop();
            }
        }
    }
    
    int add(int val) {
        if(pq.size()>=k) {
            if(val>pq.top()) {
                pq.push(val);
                pq.pop();
            }
        } else {
            pq.push(val);
        }
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */