class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int d = matrix.size() * matrix[0].size() - 1;
        
        while (l <= d) {
            int middle = (d - l) / 2 + l;
            int i = middle / matrix[0].size();
            int j = middle - i * matrix[0].size();

            if (matrix[i][j] > target)
                d = middle-1;
            else if (matrix[i][j] < target)
                l = middle+1;
            else
                return true;
        }

        return false;
    }
};
