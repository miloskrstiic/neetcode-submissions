#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // std::vector<int> result;
        
        // for (int i = 0; i < nums.size()-1; i++) {
        //     for (int j = i+1; j < nums.size(); j++) {
                
        //         if (nums[j] + nums[i] == target) {
        //             result.push_back(i);
        //             result.push_back(j);
        //             return result;
        //         }
        //     }
        // }
        // return result;
        std::unordered_map<int, int> mapa;

        for (int i = 0; i < nums.size(); i++) {
            if (mapa.find(target - nums[i]) != mapa.end())
                return {mapa[target - nums[i]], i};

            mapa[nums[i]] = i;
        }
        return {};
    }
};
