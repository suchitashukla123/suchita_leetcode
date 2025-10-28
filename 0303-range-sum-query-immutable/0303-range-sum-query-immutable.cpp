class NumArray {
private:
    vector<int> prefix;  // prefix[i] = sum of nums[0..i-1]
    
public:
    // Constructor to initialize prefix sums
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    // Return the sum of elements between indices left and right inclusive
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */