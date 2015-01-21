/**
 * Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 * For example,
 * 
 * Consider the following matrix:
 * 
 * [
 *   [1,   3,  5,  7],
 *   [10, 11, 16, 20],
 *   [23, 30, 34, 50]
 * ]
 * Given target = 3, return true.
 */

class Solution {
public:
	bool binarySearch(vector<vector<int> > &matrix, int begin, int end, int n, int target) {
		if(begin == end)	return matrix[begin / n][begin % n] == target;
		if(begin > end)	return false;
		int mid = (begin + end) / 2;
		if(matrix[mid / n][mid % n] == target) {
			return true;
		} else if(matrix[mid / n][mid % n] > target) {
			return binarySearch(matrix, begin, mid - 1, n, target);
		} else {
			return binarySearch(matrix, mid + 1, end, n, target);
		}
	}
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if(matrix.size() == 0)	return false;
    	int m = matrix.size(), n = matrix[0].size();
    	return binarySearch(matrix, 0, m * n - 1, n, target);
    }
};