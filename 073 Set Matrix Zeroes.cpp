/**
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 * 
 * click to show follow up.
 * 
 * Follow up:
 * Did you use extra space?
 * A straight forward solution using O(mn) space is probably a bad idea.
 * A simple improvement uses O(m + n) space, but still not the best solution.
 * Could you devise a constant space solution?
 */

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
    	int m = matrix.size(), n = matrix[0].size();
    	bool firstRow = false, firstVol = false;
    	for(int j = 0;j < n;j ++) {
    		if(matrix[0][j] == 0) {
    			firstRow = true;
    		}
    	}
    	for(int i = 0;i < m;i ++) {
    		if(matrix[i][0] == 0) {
    			firstVol = true;
    		}
    	}
    	for(int i = 1;i < m;i ++) {
    		for(int j = 1;j < n;j ++) {
    			if(matrix[i][j] == 0) {
    				matrix[i][0] = matrix[0][j] = 0;
    			}
    		}
    	}
    	for(int i = 1;i < m;i ++) {
    		for(int j = 1;j < n;j ++) {
    			if(matrix[i][0] == 0 || matrix[0][j] == 0) {
    				matrix[i][j] = 0;
    			}
    		}
    	}
    	if(firstRow) {
    		for(int j = 0;j < n;j ++) {
				matrix[0][j] = 0;
			}
    	}
    	if(firstVol) {
    		for(int i = 0;i < m;i ++) {
    			matrix[i][0] = 0;
    		}
    	}
    }
};