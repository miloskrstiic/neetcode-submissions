#include <set>
#include <iostream>
#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        return std::set(nums.begin(), nums.end()).size() != nums.size();
    }
};