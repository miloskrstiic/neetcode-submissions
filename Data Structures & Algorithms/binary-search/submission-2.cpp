class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int l = 0;
        int d = nums.size() - 1;
        while (l <= d) {
            int middle = (d - l)/2 + l;
            if (nums[middle] < target)
                l = middle+1;
            else if (nums[middle] > target)
                d = middle-1;
            else 
                return middle;
        }
        return -1;
    }
};
