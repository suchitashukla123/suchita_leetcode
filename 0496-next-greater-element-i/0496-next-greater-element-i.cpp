class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> nge2(n, -1); 
        stack<int> st;

       
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nge2[i] = st.top();
            }
            st.push(nums2[i]);
        }

        
        vector<int> result;
        result.reserve(nums1.size());

        for (int num : nums1) {
            
            for (int j = 0; j < n; j++) {
                if (nums2[j] == num) {
                    result.push_back(nge2[j]);
                    break;
                }
            }
        }

        return result;
    }
};
