/**
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 * 
 * For example,
 * Given n = 3,
 * 
 * You should return the following matrix:
 * [
 *  [ 1, 2, 3 ],
 *  [ 8, 9, 4 ],
 *  [ 7, 6, 5 ]
 * ]
 */

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > ans;
    	if(n == 0)	return ans;
    	for(int i = 0;i < n;i ++) {
    		ans.push_back(vector<int>(n));
    	}

    	int levels = (n + 1) / 2, num = 1;
    	for(int level = 0; level < levels;level ++) {
    		if(level == (n - 1 - level)) {
    			ans[level][level] = num ++;
    			continue;
    		}
    		for(int j = level;j < n - 1 - level;j ++)
    			ans[level][j] = num ++;
    		for(int i = level;i < n - 1 - level;i ++)
    			ans[i][n - 1 - level] = num ++;
    		for(int j = n - 1 - level;j > level;j --)
    			ans[n - 1 - level][j] = num ++;
    		for(int i = n - 1 - level;i > level;i --)
    			ans[i][level] = num ++;
    	}
    	return ans;
    }
};