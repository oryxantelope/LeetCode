/**
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * For example:
 * Given array A = [2,3,1,1,4]
 * 
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 */

class Solution {
public:
	int jump(int A[], int n) {
    	if(n <= 1)	return 0;
    	if(A[0] >= n - 1)	return 1;
    	int maxLength = A[0], ans = 0, last = 0;
    	for(int i = 0;i < n;i ++) {
    		if(i <= maxLength && i + A[i] >= n - 1)
    			return ans + 1;
    		if(i > maxLength)
    			return -1;
    		if(i + A[i] > maxLength) {
    			maxLength = i + A[i];
    		}
    		if(i >= last) {
    			ans ++;
    			last = maxLength;
    		}
    	}
    	return ans;
    }
};