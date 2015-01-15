/**
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * You may assume that there will be only one unique solution.
 */

class Solution {
public:
	bool solveSudoku(vector<vector<char> > &board, int index, bool row[][9], bool vol[][9], bool rec[][9]) {
		if(index == 81)
			return true;
		int i = index / 9, j = index % 9;
		if(board[i][j] != '.') {
			return solveSudoku(board, index + 1, row, vol, rec);
		} else {
			for(int number = 0;number < 9;number ++) {
				if(row[i][number]
				   || vol[j][number]
				   || rec[(i / 3) * 3 + (j / 3)][number])
					continue;
				board[i][j] = '1' + number;
				row[i][number] = true;
				vol[j][number] = true;
				rec[(i / 3) * 3 + (j / 3)][number] = true;
				if(solveSudoku(board, index + 1, row, vol, rec))
					return true;
				board[i][j] = '.';
				row[i][number] = false;
				vol[j][number] = false;
				rec[(i / 3) * 3 + (j / 3)][number] = false;
			}
			return false;
		}
	}
    void solveSudoku(vector<vector<char> > &board) {
    	bool row[9][9], vol[9][9], rec[9][9];
    	memset(row, 0, sizeof(row));
    	memset(vol, 0, sizeof(vol));
    	memset(rec, 0, sizeof(rec));
    	for(int i = 0;i < 9;i ++)
    		for(int j = 0;j < 9;j ++)
    			if(board[i][j] != '.') {
    				row[i][board[i][j] - '1'] = true;
					vol[j][board[i][j] - '1'] = true;
					rec[(i / 3) * 3 + (j / 3)][board[i][j] - '1'] = true;
    			}
    	solveSudoku(board, 0, row, vol, rec);
    }
};