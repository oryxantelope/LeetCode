/**
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * 
 * How many possible unique paths are there?
 * 
 * 
 * Above is a 3 x 7 grid. How many possible unique paths are there?
 * 
 * Note: m and n will be at most 100.
 */

class Solution {
public:
	int C(int a, int b, int board[][210]) {
		if(a == 1 || b == 0 || a == b)	return 1;
		if(b == 1)	return a;
		if(board[a][b] == 0)
			board[a][b] = C(a - 1, min(a - 1 - b, b), board) + C(a - 1, min(a - b, b - 1), board);
		return board[a][b];
	}
	int uniquePaths(int m, int n) {
		int board[210][210] = {};
		memset(board, 0, sizeof(int) * 210 * 210);
		return C(m + n - 2, min(m, n) - 1, board);
    }
};