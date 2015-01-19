/**
 * You are given an n x n 2D matrix representing an image.
 * 
 * Rotate the image by 90 degrees (clockwise).
 * 
 * Follow up:
 * Could you do this in-place?
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
    	int n = matrix.size(), tmp;
    	for(int i = 0;i < n / 2;i ++) {
    		for(int j = i;j < n - i - 1;j ++) {
    			tmp = matrix[i][j];
    			matrix[i][j] = matrix[n - 1 - i - (j - i)][i];
    			matrix[n - 1 - i - (j - i)][i] = matrix[n - i - 1][n - 1 - i - (j - i)];
    			matrix[n - i - 1][n - 1 - i - (j - i)] = matrix[j][n - i - 1];
    			matrix[j][n - i - 1] = tmp;
    		}
    	}
    }
};