/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 * 
 * http://www.leetcode.com/wp-content/uploads/2012/08/rainwatertrap.png
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
 */

class Solution {
public:
    int trap(int A[], int n) {
    	int left[n], sum = 0;
    	memset(left, 0, sizeof(int) * n);
    	for(int i = 1;i < n - 1;i ++) {
    		left[i] = max(A[i - 1], left[i - 1]);
    	}
    	for(int i = n - 2;i >= 0;i --) {
    		sum += (min(left[i], max(A[i + 1], left[i + 1])) - A[i]) > 0
    				? (min(left[i], max(A[i + 1], left[i + 1])) - A[i]) : 0;
    		left[i] = max(A[i + 1], left[i + 1]);
    	}
    	return sum;
    }
};