class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        int left = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Current element already exists
            // in the previous k elements
            if (st.find(nums[right]) != st.end()) {
                return true;
            }

            // Add current element to window
            st.insert(nums[right]);

            // Window size should not exceed k
            if (right - left >= k) {
                st.erase(nums[left]);
                left++;
            }
        }

        return false;
    }
};