class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        for (auto num: nums)
            freq[num]++;

        vector<vector<int>> buckets(nums.size() + 1);
        for (auto [key, value] : freq)
            buckets[value].push_back(key);
        
        vector<int> result;
        for(int i = buckets.size() - 1; i > 0; i--){
            for(auto element : buckets[i]) {
                result.push_back(element);

                if (result.size() == k)
                    return result;
            }
        }
        return result;
    }
};
