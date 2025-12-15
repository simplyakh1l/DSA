class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int f = nums[i];
            for (int j = i + 1; j < n; j++) {
                int s = nums[j];
                if (f + s == t) {
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;
    }
};