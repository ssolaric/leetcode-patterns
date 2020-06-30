// https://www.youtube.com/watch?v=zx5Sw9130L0
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        stack<pair<int, int>> s; // pair (index, height)
        for (int i = 0; i < n; i++) {
            int start = i;
            while (!s.empty() && heights[i] < s.top().second) {
                auto [index, height] = s.top();
                s.pop();
                maxArea = max(maxArea, height * (i - index));
                start = index;
            }
            // Save the last index popped, which corresponds to the element farthest away from i
            // where the height of this element is still greater than heights[i]
            // The area rectangle starts from this index, we save it as the corresponding index for
            // heights[i], instead of i
            s.push({start, heights[i]});<
        }
        // At the end, there could be some remaining elements in the stack. Pop them all.
        while (!s.empty()) {
            auto [index, height] = s.top();
            s.pop();
            maxArea = max(maxArea, height * (n - index));
        }
        return maxArea;                                     
    }
};