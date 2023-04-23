class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the intervals by end coordinate. We notice that each "cluster" of balloons
        // can be popped using a single arrow. A new interval enters the cluster if
        // it can intersect the first balloon of this cluster.
        // ------
        //  -------
        //           --
        //          -------
        //          ---------
        //             ----------
        int n = points.size();
        if (n == 0) return 0;
        sort(points.begin(), points.end(), [](auto& i1, auto& i2) {
            if (i1[1] != i2[1]) {
                return i1[1] < i2[1];    
            }
            return i1[0] < i2[0];
        });
        int firstEnd = points[0][1];
        int ans = 1;
        for (int i = 1; i < n; i++) {
            // No intersection
            if (firstEnd < points[i][0]) {
                // New cluster
                ans++;
                firstEnd = points[i][1];
            }
        }
        return ans;
    }
};