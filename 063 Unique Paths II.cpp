/**
 * Follow up for "Unique Paths":
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths would there be?
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * For example,
 * There is one obstacle in the middle of a 3x3 grid as illustrated below.
 * 
 * [
 *   [0,0,0],
 *   [0,1,0],
 *   [0,0,0]
 * ]
 * The total number of unique paths is 2.
 * 
 * Note: m and n will be at most 100.
 */

class Solution {
public:
	void cal(int i, int j, int m, int n, vector<vector<int> > &obstacleGrid, int **ans) {
		if(obstacleGrid[i][j] == 1)
			ans[i][j] = 0;
		else {
			if(j + 1 <= n - 1)
				ans[i][j] += ans[i][j + 1];
			if(i + 1 <= m - 1)
				ans[i][j] += ans[i + 1][j];
		}
	}
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	int m = obstacleGrid.size(), n, i, j;
    	if(m == 0)	return 0;
    	n = obstacleGrid[0].size();
    	int **ans = new int *[m];
    	for(i = 0;i < m;i ++) {
    		ans[i] = new int[n];
    		memset(ans[i], 0, sizeof(int) * n);
    	}
    	ans[m - 1][n - 1] = (obstacleGrid[m - 1][n - 1] == 1) ? 0 : 1;

    	for(i = m - 1, j = n - 2;j > 0;j --) {
    		for(int ii = i, jj = j;ii >= 0 && jj <= n - 1; ii--, jj++) {
    			cal(ii, jj, m, n, obstacleGrid, ans);
    		}
    	}
    	for(i = m - 1, j = 0;i >= 0;i --) {
    		for(int ii = i, jj = j;ii >= 0 && jj <= n - 1; ii--, jj++) {
    			cal(ii, jj, m, n, obstacleGrid, ans);
    		}
    	}
    	j = ans[0][0];
    	for(i = 0;i < m;i ++) {
    		delete[] ans[i];
    	}
    	delete [] ans;
    	return j;
    }
};