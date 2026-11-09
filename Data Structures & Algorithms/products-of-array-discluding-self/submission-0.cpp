class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        prefix[0] = 1;
        for (int i = 1; i < nums.size(); i++)
            prefix[i] = prefix[i-1] * nums[i-1];

        vector<int> sufix(nums.size());
        sufix[nums.size()-1] = 1;
        for (int i = nums.size()-2; i >= 0; i--)
            sufix[i] = nums[i+1] * sufix[i+1];
        
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
            result.push_back(prefix[i] * sufix[i]);
        
        return result;
    }
};
