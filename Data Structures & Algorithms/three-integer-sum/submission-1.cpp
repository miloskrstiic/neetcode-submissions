class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            int fixed_i = nums[i];
            int j = i+1;
            int k = n-1;
            while (j < k) {
                int currentSum = fixed_i + nums[j] + nums[k];
                if (currentSum < 0)
                    j++;
                else if (currentSum > 0)
                    k--;
                else if (i != j != k) {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1])
                        j++;
                }
            }
        }

        return result;
    }
};
