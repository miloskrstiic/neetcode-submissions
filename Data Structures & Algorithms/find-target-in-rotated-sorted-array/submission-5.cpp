class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int d = nums.size()-1;
        while (l < d) {
            int s = (d - l) / 2 + l;
            if (nums[s] < nums[d])
                d = s;
            else
                l = s+1;
        }
        return d;
    }

    int search(vector<int>& nums, int target) {
        int pivot = findMin(nums);
        int l = 0;
        int d = pivot - 1;

        if (target >= nums[pivot] && target <= nums[nums.size()-1]) {
            l = pivot;
            d = nums.size()-1;
        }

        while (l <= d) {
            int s = (d - l) / 2 + l;

            if (nums[s] == target)
                return s;

            if (nums[s] < target)
                l = s+1;
            else
                d = s-1;
        }
        return -1;
    }
};
