/**
 * Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
    	if(grid.size() == 0)	return 0;
    	int m = grid.size(), n = grid[0].size(), i, j, ii, jj;
    	int board[m][n];
    	memset(board, 0, sizeof(int) * m * n);
    	board[m - 1][n - 1] = grid[m - 1][n - 1];
    	for(i = m - 1,j = n - 2;j >= 0;j --) {
    		for(ii = i, jj = j;ii >= 0 && jj <= n - 1;ii --, jj ++) {
    			if(ii + 1 > m - 1)
    				board[ii][jj] = grid[ii][jj] + board[ii][jj + 1];
    			else if(jj + 1 > n - 1)
    				board[ii][jj] = grid[ii][jj] + board[ii + 1][jj];
    			else
    				board[ii][jj] = grid[ii][jj] + min(board[ii][jj + 1], board[ii + 1][jj]);
    		}
    	}
    	for(i = m - 2, j = 0;i >= 0;i --) {
    		for(ii = i, jj = j;ii >= 0 && jj <= n - 1;ii --, jj ++) {
				if(ii + 1 > m - 1)
					board[ii][jj] = grid[ii][jj] + board[ii][jj + 1];
				else if(jj + 1 > n - 1)
					board[ii][jj] = grid[ii][jj] + board[ii + 1][jj];
				else
					board[ii][jj] = grid[ii][jj] + min(board[ii][jj + 1], board[ii + 1][jj]);
			}
    	}
    	return board[0][0];
    }
};