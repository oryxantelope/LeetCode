/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array A = [1,1,2],
 * 
 * Your function should return length = 2, and A is now [1,2].
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
    	if(n == 1 || n == 0) return n;
    	int last = 0, next = 1;
    	for(;next < n;next ++) {
    		if(A[next] != A[last]) {
    			A[++last] = A[next];
    		}
    	}
    	return last + 1;
    }
};