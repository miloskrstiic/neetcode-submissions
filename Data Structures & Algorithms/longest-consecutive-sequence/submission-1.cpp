class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> skup;
        for (int num: nums)
            skup.insert(num);

        int max_counter = 0;
        int counter = 1;
        for (int num: skup) {
            if (skup.find(num-1) == skup.end()) {
                counter = 1;
                int helper = num + 1;
                while (skup.find(helper) != skup.end()) {
                    counter++;
                    helper++;
                }
            }
            max_counter = max(max_counter, counter);
        }
        return max_counter;
    }
};
