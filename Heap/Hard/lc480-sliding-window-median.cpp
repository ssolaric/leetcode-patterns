class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int, greater<int>> firstHalf;
        multiset<int> secondHalf;
        
        auto median = [k, &firstHalf, &secondHalf]() {
            if (k % 2 == 0) {
                return ((double)*firstHalf.begin() + *secondHalf.begin()) / 2.0;
            }
            return (double)*firstHalf.begin();
        };
        
        auto balance = [&firstHalf, &secondHalf]() {
            while (firstHalf.size() < secondHalf.size()) {
                firstHalf.insert(*secondHalf.begin());
                secondHalf.erase(secondHalf.begin());
            }
        };
        
        vector<double> ans;
        for (int i = 0; i < k; i++) {
            secondHalf.insert(nums[i]);
        }
        balance();
        ans.push_back(median());
        
        for (int i = k; i < nums.size(); i++) {
            auto it2 = secondHalf.find(nums[i - k]);
            if (it2 != secondHalf.end()) {
                secondHalf.erase(it2);
            }
            else {
                auto it1 = firstHalf.find(nums[i - k]);
                firstHalf.erase(it1);
            }
            
            firstHalf.insert(nums[i]);
            secondHalf.insert(*firstHalf.begin());
            firstHalf.erase(firstHalf.begin());
            balance();
            
            ans.push_back(median());
        }
        return ans;
    }
};
