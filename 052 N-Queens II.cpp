/**
 * Follow up for N-Queens problem.
 * 
 * Now, instead outputting board configurations, return the total number of distinct solutions.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/03/8-queens.png
 */

class Solution {
public:
	int foo(int i, int n, bool * left, bool * right, bool * volume) {
		if(i == n) {
			return 1;
		}
		int cnt = 0;
		for(int j = 0;j < n;j ++) {
			if(volume[j] || left[j - i + n - 1] || right[i + j]) {
				continue;
			}
			volume[j] = true;
			left[j - i + n - 1] = true;
			right[i + j] = true;
			cnt += foo(i + 1, n, left, right, volume);
			volume[j] = false;
			left[j - i + n - 1] = false;
			right[i + j] = false;
		}
		return cnt;
	}
    int totalNQueens(int n) {
    	bool left[2 * n - 1], right[2 * n - 1], volume[n];
    	memset(left, 0, sizeof(bool) * (2 * n - 1));
    	memset(right, 0, sizeof(bool) * (2 * n - 1));
    	memset(volume, 0, sizeof(bool) * n);
    	return foo(0, n, left, right, volume);
    }
};