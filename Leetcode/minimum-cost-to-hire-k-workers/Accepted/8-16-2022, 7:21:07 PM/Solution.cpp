// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
/*
    The important point to note for this problem is that 
    for point 1 to be true : givenwage1/givenwage2 = cost1/cost2
    wage1/cost1 = wage2/cost2 = wage3/cost3 .......
    
    We'll get the ratios ie (wage/cost)  for all elements. We try 
    to use low ratios for better results. So we'll sort the elements based
    on the ratios. This ensures the first point and min cost.
    
    For 2nd point we need to take a ratio such that the actual wage given 
    to each person is greater than equal to their specified wage. For this we can 
    use the kth biggest ratio. The ans would be ratio[k]*(totalQuality of k starting elements)
    
    We can also see that when we add another element with ratio bigger than the current ratio, we
    need to remove an element from existing elements as we only need k people. The totalhappiness 
    of k elements may be decreased (Large quality elements cost us more. Hence
    is favourable to remove large quality elements). We keep doing this for all the windows of k
    sizes using sliding window. For every window we take the min(finalans, current window ans)
*/
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        priority_queue<pair<int,int>> pq;
        vector<pair<double,int>> ratios;
        
        for(int i=0;i<n;i++) {
            ratios.push_back({wage[i]*1.0/quality[i], i});
        }
        sort(ratios.begin(), ratios.end());
        
        int totalquality = 0;
        for(int i=0;i<k;i++) {
            int idx = ratios[i].second;
            pq.push({quality[idx], idx});
            totalquality += quality[idx];
        }
        double ans = (totalquality*ratios[k-1].first);
        
        for(int i=k;i<n;i++) {
            auto top = pq.top(); pq.pop();
            totalquality-=quality[top.second];
            
            int newidx = ratios[i].second;
            pq.push({quality[newidx], newidx});
            totalquality+=quality[newidx];
            
            double curr = ratios[i].first*totalquality;
            ans = min(ans, curr);
        }
        return ans;
    }
};