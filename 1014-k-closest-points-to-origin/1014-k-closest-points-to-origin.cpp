class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        //vector<int> ptSqDistances(points.size(), 0);
        priority_queue<pair<int, vector<int>>> maxHeap;
        //loop over all the points to calculate their distances
        for (int i=0; i < points.size(); ++i){
            vector<int> loc {points[i][0], points[i][1]};
            
            int SqDist = loc[0]*loc[0] + loc[1]*loc[1];
            
            if (maxHeap.size() <= k || SqDist < maxHeap.top().first){
                maxHeap.push({SqDist, loc});

                if (maxHeap.size() > k)
                    maxHeap.pop();
            }
        }

        vector<vector<int>> results;
        while (!maxHeap.empty())
        {
            results.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        
        return results;
    }
};