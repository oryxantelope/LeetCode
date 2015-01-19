/**
 * Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 * 
 * For example,
 * Given the following matrix:
 * 
 * [
 *  [ 1, 2, 3 ],
 *  [ 4, 5, 6 ],
 *  [ 7, 8, 9 ]
 * ]
 * You should return [1,2,3,6,9,8,7,4,5].
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
    	vector<int> ans;
    	if(matrix.size() == 0)	return ans;
    	if(matrix.size() == 1)	return matrix[0];
    	int m = matrix.size(), n = matrix[0].size();
    	int left, top, right, bottom;
    	for(int i = 0;;i ++) {
    		left = top = i;
    		right = n - 1 - i;
    		bottom = m - 1 - i;
    		if(top == bottom) {
    			for(int j = left;j <= right;j ++)
    				ans.push_back(matrix[top][j]);
    			break;
    		} else if(left == right) {
    			for(int j = top;j <= bottom;j ++)
    				ans.push_back(matrix[j][left]);
    			break;
    		} else if(left < right && top < bottom){
    			for(int j = left;j < right;j ++)
    				ans.push_back(matrix[top][j]);
    			for(int j = top;j < bottom;j ++)
    				ans.push_back(matrix[j][right]);
    			for(int j = right;j > left;j --)
    				ans.push_back(matrix[bottom][j]);
    			for(int j = bottom;j > top;j --)
    				ans.push_back(matrix[j][left]);
    		} else {
    		    break;
    		}
    	}
    	return ans;
    }
};