class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows;
        unordered_map<int, unordered_set<char>> columns;
        unordered_map<int, unordered_set<char>> squares;
        
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.')
                    continue;
                
                if (rows[i].find(board[i][j]) != rows[i].end())
                    return false;
                
                if (columns[j].find(board[i][j]) != columns[j].end())
                    return false;
                
                int square = (i / 3) * 3 + (j / 3);
                if (squares[square].find(board[i][j]) != squares[square].end())
                    return false;
                
                rows[i].insert(board[i][j]);
                columns[j].insert(board[i][j]);
                squares[square].insert(board[i][j]);
            }
        }

        return true;
    }
};
