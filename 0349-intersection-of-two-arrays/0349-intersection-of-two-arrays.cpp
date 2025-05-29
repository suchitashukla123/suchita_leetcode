class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> intersect(nums1.begin(), nums1.end());
        unordered_set<int> added;
        vector<int> nums3;

        for (int num : nums2) {
            if (intersect.count(num) && !added.count(num)) {
                nums3.push_back(num);
                added.insert(num);
            }
        }

        return nums3;
    }
};