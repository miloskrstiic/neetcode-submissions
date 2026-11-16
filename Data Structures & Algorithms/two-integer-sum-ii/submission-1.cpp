class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int j = numbers.size()-1;
        int i = 0;
        while (i < j) {
            if (numbers[i] + numbers[j] > target) {
                j--;
                continue;
            }

            if (numbers[i] + numbers[j] < target) {
                i++;
                continue;
            }

            if (numbers[i] + numbers[j] == target)
                return {i+1, j+1};
        }

        return {};
    }
};
