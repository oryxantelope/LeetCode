/**
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 * http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 * 
 * For example,
 * There exist two distinct solutions to the 4-queens puzzle:
 * [
 *  [".Q..",  // Solution 1
 *   "...Q",
 *   "Q...",
 *   "..Q."],
 * 
 *  ["..Q.",  // Solution 2
 *   "Q...",
 *   "...Q",
 *   ".Q.."]
 * ]
 */

class Solution {
public:
	void foo(int i, int n, bool * left, bool * right, bool * volume, vector<vector<string> > &ans, vector<int> &tmp) {
		if(i == n) {
			vector<string> solution;
			for(int j = 0;j < n;j ++) {
				string row;
				for(int k = 0;k < n;k ++) {
					row += (k == tmp[j]) ? 'Q' : '.';
				}
				solution.push_back(row);
			}
			ans.push_back(solution);
		} else {
			for(int j = 0;j < n;j ++) {
				if(volume[j] || left[j - i + n - 1] || right[i + j]) {
					continue;
				}
				volume[j] = true;
				left[j - i + n - 1] = true;
				right[i + j] = true;
				tmp.push_back(j);
				foo(i + 1, n, left, right, volume, ans, tmp);
				volume[j] = false;
				left[j - i + n - 1] = false;
				right[i + j] = false;
				tmp.pop_back();
			}
		}
	}
    vector<vector<string> > solveNQueens(int n) {
    	vector<vector<string> > ans;
    	vector<int> tmp;
    	bool left[2 * n - 1], right[2 * n - 1], volume[n];
		memset(left, 0, sizeof(bool) * (2 * n - 1));
		memset(right, 0, sizeof(bool) * (2 * n - 1));
		memset(volume, 0, sizeof(bool) * n);
		foo(0, n, left, right, volume, ans, tmp);
		return ans;
	}
};