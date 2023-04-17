class NumArray {
public:
    NumArray(vector<int>& nums): S(nums.size() + 1) {
        for (int i = 0; i < nums.size(); i++) {
            S[i+1] = S[i] + nums[i];
        }
    }
    
    int sumRange(int i, int j) {
        return S[j+1] - S[i];
    }
private:
    vector<int> S;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */