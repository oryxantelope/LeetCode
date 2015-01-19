/**
 * Given an unsorted integer array, find the first missing positive integer.
 * 
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 * 
 * Your algorithm should run in O(n) time and uses constant space.
 */

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
    	for(int i = 0;i < n;i ++) {
    		if(A[i] <= n && A[i] > 0 && A[i] != i + 1) {
    			for(int tmp = A[i];tmp <= n && tmp > 0 && tmp != A[tmp - 1];) {
    				swap(tmp, A[tmp - 1]);
    			}
    		}
    	}
    	for(int i = 0;i < n;i ++) {
    		if(!(A[i] <= n && A[i] > 0 && A[i] == i + 1)) {
    			return i + 1;
    		}
    	}
    	return n + 1;
    }
};