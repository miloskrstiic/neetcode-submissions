class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        vector<pair<int,int>> sorted;
        for (int i = 0; i < nums.size(); i++)
            sorted.push_back({nums[i], i});

        sort(sorted.begin(), sorted.end(), [](const auto a, const auto b) {
            return a.first < b.first;
        });

        int n = nums.size();
        for (int i = 0; i < n-2; i++) {
            int fixed_i = sorted[i].first;
            int j = i+1;
            int k = n-1;
            while (j < k) {
                int currentSum = fixed_i + sorted[j].first + sorted[k].first;
                if (currentSum < 0)
                    j++;
                else if (currentSum > 0)
                    k--;
                else if (i != j != k) {
                    vector<int> triplet = {sorted[i].first, sorted[j].first, sorted[k].first};

                    if (find(result.begin(), result.end(), triplet) == result.end())
                        result.push_back(triplet);
                    j++;
                }
            }
        }

        return result;
    }
};
