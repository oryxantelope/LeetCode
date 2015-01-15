/**
 * Determine if a Sudoku is valid, according to: [Sudoku Puzzles - The Rules](http://sudoku.com.au/TheRules.aspx).
 * 
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 * 
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

class Solution {
public:
	bool isValid(int* valid) {
		for(int i = 1;i <= 9;i ++) {
			if(valid[i] > 1)
				return false;
		}
		return true;
	}
    bool isValidSudoku(vector<vector<char> > &board) {
    	int validRow[10] = {}, validVol[10] = {};
    	for(int i = 0;i < 9;i ++) {
    		memset(validRow, 0, sizeof(validRow));
    		memset(validVol, 0, sizeof(validVol));
    		for(int j = 0;j < 9;j ++) {
    			if(board[i][j] != '.')
    				validRow[board[i][j] - '0'] ++;
    			if(board[j][i] != '.')
    			validVol[board[j][i] - '0'] ++;
    		}
    		if(!isValid(validRow))	return false;
    		if(!isValid(validVol))	return false;
    	}

    	for(int i = 0;i < 9;i += 3){
    		for(int j = 0;j < 9;j += 3) {
    			memset(validRow, 0, sizeof(validRow));
    			for(int ii = i;ii < i + 3;ii ++) {
    				for(int jj = j;jj < j + 3; jj ++) {
    					if(board[ii][jj] != '.')
    						validRow[board[ii][jj] - '0'] ++;
    				}
    			}
    			if(!isValid(validRow))	return false;
    		}
    	}
    	return true;
    }
};