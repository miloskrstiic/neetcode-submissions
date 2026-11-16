class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maximum = -1;

        int i = 0;
        int j = heights.size() - 1;
        while (i < j) {
            int formula = (j - i) * min(heights[i], heights[j]);
            maximum = max(maximum, formula);
            if (heights[i] < heights[j])
                i++;
            else
                j--;
        }

        return maximum;
    }
};
