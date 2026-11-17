class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int d = nums.size()-1;
        int s = 0;
        while (l < d) {
            s = (d - l) / 2 + l;
            if (nums[s] < nums[d])
                d = s;
            else
                l = s+1;
        }
        return nums[d];
    }
};
