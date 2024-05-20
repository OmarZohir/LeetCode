class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<int,int>> row_vec;
        vector<unordered_map<int,int>> col_vec;
        vector<unordered_map<int,int>> box_vec;
        const int sudoku_size = 9;
        row_vec.resize(sudoku_size);
        col_vec.resize(sudoku_size);
        box_vec.resize(sudoku_size);
        for (int i = 0; i < sudoku_size; ++i){
            for (int j = 0; j < sudoku_size; ++j){
                if (board[i][j] == '.')
                    continue;
                else{
                    int num = board[i][j] - '0';
                    // do the row check (check that each row has unique elements)
                    row_vec[i][num]++;
                    if (row_vec[i][num] > 1)
                        return false; 

                    // do the column check (check that each column has unique elements)
                    col_vec[j][num]++;
                    if (col_vec[j][num] > 1)
                        return false; 

                    // do the subset check
                    int box_idx = int(j/3)*3 + int(i/3);
                    box_vec[box_idx][num]++;
                    if (box_vec[box_idx][num] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};